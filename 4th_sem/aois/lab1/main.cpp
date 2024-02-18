#include <iostream>
#include "src/DirectForm.h"

int main() {
    DirectForm t1, t2;
    cout << "Enter two int nums:" << endl;
    cin >> t1 >> t2;
    if (t1 > t2)
        cout << t1 << " > " << t2 << endl;
    else if (t1 < t2)
        cout << t1 << " < " << t2 << endl;
    else
        cout << t1 << " = " << t2 << endl;

    return 0;
}
