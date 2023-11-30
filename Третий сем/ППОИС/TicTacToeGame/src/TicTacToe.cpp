#include "../inc/TicTacToe.h"

TicTacToe::TicTacToe() {
    size_ = 3;
    freeCells_ = size_ * size_;
    field_ = new GameLine[size_];

    for (size_t i = 0; i < size_; i++) {
        field_[i].resize(size_);
    }
}

TicTacToe::TicTacToe(size_t size) {
    if (size < 3 || size > 26)
        size_ = 3;
    else
        size_ = size;

    freeCells_ = size_ * size_;
    field_ = new GameLine[size_];

    for (size_t i = 0; i < size_; i++) {
        field_[i].resize(size_);
    }
}

std::string TicTacToe::getInput(){
    std::string input;
    std::cout << "Enter cords of the cell in format A1\n";
    std::getline(std::cin, input);
    return input;
}
///
/// \param input
/// \return
bool TicTacToe::checkInput(std::string input) {
    if (input.size() < 2) {
        std::cout << "It's too short to be coordinate" << std::endl;
        return false;
    }

    for(int i = 0; i < input.size(); i++){
        while (input[i] == ' ')
            input.erase(i, 1);
    }

    if (input.size() < 2) {
        std::cout << "It's too short(without ' ') to be coordinate" << std::endl;
        return false;
    }

    if (input[0] < 'A' || input[0] > 'Z') {
        std::cout << "No letter on the first position" << std::endl;
        return false;
    }

    for(int i = 1; i < input.size(); i++){
        if (input[i] < '0' || input[i] > '9') {
            std::cout << "Something strange with number in your coordinate" << std::endl;
            return false;
        }
    }

    return true;
}

pair<char, size_t> TicTacToe::stringParsing(std::string input) {
    pair<char, size_t> cords = {'A', 1};
    cords.first = input[0];
    std::string secondCord = input.substr(1, input.size() - 1);
    cords.second = std::stoi(secondCord);
    return cords;
}
///
/// \param cords
/// \return
pair<size_t, size_t> TicTacToe::inputTranslate(pair<char, size_t> cords) {
    pair<size_t, size_t> numericCords = {0, 0};
    numericCords.second = -1 * (65 - cords.first);
    numericCords.first = cords.second - 1;
    return numericCords;
}

pair<size_t, size_t> TicTacToe::inputProcessing() {
    std::string input;

    bool flag;
    do {
        input = getInput();
        flag = checkInput(input);

    }
    while (!flag);

    pair<char, size_t> classicCords = stringParsing(input);
    pair<size_t, size_t> numericCords = inputTranslate(classicCords);
    return numericCords;
}

bool TicTacToe::isInside(pair<size_t, size_t> cords) {
    if (cords.first < 0 || cords.first >= size_)
        return false;

    if (cords.second < 0 || cords.second > size_)
        return false;

    return true;
}

bool TicTacToe::getCell(pair<size_t, size_t> cords, bool player) {
    if (cords.first >= size_) {
        std::cout << "This cell doesn't exist(numeric cord)" << std::endl;
        return false;
    }
    if (cords.second >= size_) {
        std::cout << "This cell doesn't exist(letter cord)" << std::endl;
        return false;
    }

    if (!field_[cords.first][cords.second].isEmpty()) {
        std::cout << "This cell is already occupied" << std::endl;
        return false;
    }

    field_[cords.first][cords.second].setSymbol(player);
    print_field();
    freeCells_--;
    return true;
}

bool TicTacToe::winCheck(pair<size_t, size_t> cords, bool player) {
    GameCell winCell(player);
    pair<size_t, size_t> checkCords = {0, 0};
    GameCell currentCell;

    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i == 0 && j == 0)
                continue;

            checkCords = {cords.first + i, cords.second + j};

            if (!isInside(checkCords))
                continue;

            currentCell = field_[checkCords.first][checkCords.second];
            if (currentCell == winCell) {

                checkCords = {cords.first + 2 * i, cords.second + 2 * j};
                bool flag = isInside(checkCords);
                if (flag) {
                    currentCell = field_[checkCords.first][checkCords.second];
                    flag = currentCell == winCell;
                }
                if (flag)
                    return true;

                checkCords = {cords.first - i, cords.second - j};
                flag = isInside(checkCords);
                if (flag) {
                    currentCell = field_[checkCords.first][checkCords.second];
                    flag = currentCell == winCell;
                }
                if (flag)
                    return true;
            }
        }
    }

    return false;
}

bool TicTacToe::gameMove(bool player) {
    if(player)
        std::cout << "Turn of Player X" << std::endl;
    else
        std::cout << "Turn of Player O" << std::endl;


    bool flag;
    pair<size_t, size_t> cords = {0, 0};
    do {
        cords = inputProcessing();
        flag = getCell(cords, player);
    }
    while(!flag);

    if (winCheck(cords, player)) {
        if(player) {
            std::cout << "Congratulations! Player X won!" << std::endl;
            return true;
        }
        else {
            std::cout << "Congratulations! Player O won!" << std::endl;
            return true;
        }
    }

    return false;
}

void TicTacToe::print_field() {
    std::cout << "\n    ";
    char s = 'A';
    for(size_t  i = 0; i < size_; i++, s++){
        std::cout << " " << s << "  ";
    }

    std::cout << "\n   |";
    for(size_t i = 0; i < size_; i++){
        std::cout << "---|";
    }
    std::cout << "\n";

    for (size_t  i = 0; i < size_; i++) {

        if(i < 9)
            std::cout << i + 1 << "  |";
        else
            std::cout << i + 1 << " |";

        for (size_t j = 0; j < size_; j++) {
            if (field_[i][j].isEmpty())
                std::cout << "   |";
            else {
                if (field_[i][j].getSymbol())
                    std::cout << " X |";
                else
                    std::cout << " O |";
            }
        }

        std::cout << "\n   |";
        for(size_t j = 0; j < size_; j++){
            std::cout << "---|";
        }
        std::cout << "\n";
    }
}

void TicTacToe::game() {
    bool player = true;
    bool win = false;

    std::cout << "The Tic-tac-toe game started" << std::endl;
    print_field();

    while(!win){
        win = gameMove(player);
        if (player)
            player = false;
        else
            player = true;
        if (freeCells_ == 0) {
            std::cout << "It's draw by the way" << std::endl;
            win = true;
        }
    }
}
