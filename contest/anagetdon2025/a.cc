#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    string s;
    cin >> s;
    vector<int> list;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'N') {
            list.push_back(i);
        }
    }

    int ans = 0;
    for (auto &&idx : list) {
        for (int i = 1;; i++) {
            if (idx - i < 0 || idx + i >= (int)s.size()) break;
            if (s[idx - i] == 'A' && s[idx + i] == 'A') {
                ans++;
            } else if (s[idx - i] == s[idx + i] && s[idx + i] != 'N') {
            } else {
                break;
            }
        }
    }

    cout << ans;
    return 0;
}