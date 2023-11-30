cmake_minimum_required(VERSION 3.14)
project(TICTACTOE_TEST)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(NO_DEV ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        TicTacToe_Test
        game_cell_test.cpp
        game_line_test.cpp
        game_field_test.cpp
        tictactoe_test.cpp
        ../src/GameCell.cpp
        ../src/GameLine.cpp
        ../src/GameField.cpp
        ../src/TicTacToe.cpp
)
target_link_libraries(
        TicTacToe_Test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(TicTacToe_Test)