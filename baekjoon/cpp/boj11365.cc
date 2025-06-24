#include <algorithm>
#include <iostream>
#include <string>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    string s;
    while (1) {
        getline(cin, s);
        if (s == "END") break;
        reverse(s.begin(), s.end());
        cout << s << '\n';
    }
    return 0;
}