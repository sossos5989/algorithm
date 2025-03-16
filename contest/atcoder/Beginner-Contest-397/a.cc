#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    double c;
    cin >> c;
    if (c >= 38.0)
        cout << "1";
    else if (c >= 37.5)
        cout << "2";
    else
        cout << "3";
    return 0;
}