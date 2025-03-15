#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n;

int main() {
    fastIO;
    cin >> n;
    cout << (n >= 90   ? "A"
             : n >= 80 ? "B"
             : n >= 70 ? "C"
             : n >= 60 ? "D"
                       : "F")
         << endl;
    return 0;
}