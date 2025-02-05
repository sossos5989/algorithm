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
        int strike = 0, sum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'O')
                sum += ++strike;
            else
                strike = 0;
        }
        cout << sum << "\n";
    }
    return 0;
}