#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

string s;

int main() {
    fastIO;
    int C;
    cin >> C;
    while (C--) {
        cin >> s;
        cout << s[0] << s[s.size() - 1] << "\n";
    }
    return 0;
}