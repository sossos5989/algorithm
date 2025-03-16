#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    string s;
    cin >> s;
    int count = 0, state = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'i') {
            if (state == 1) count++;
            state = 1;
        } else {
            if (state == 0) count++;
            state = 0;
        }
    }
    cout << count + state;
    return 0;
}