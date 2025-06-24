#include <iostream>
#include <string>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    while (r--)
        cout << string(c, '*') << '\n';
    return 0;
}