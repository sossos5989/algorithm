#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    string s, bomb;
    cin >> s >> bomb;

    vector<char> v;

    for (int i = 0; i < s.size(); i++) {
        v.push_back(s[i]);
        if (v.size() >= bomb.size()) {
            bool flag = true;
            for (int i = 1; i <= bomb.size(); i++) {
                if (v[v.size() - i] != bomb[bomb.size() - i]) flag = false;
            }

            if (flag)
                for (int i = 0; i < bomb.size(); i++) {
                    v.pop_back();
                }
        }
    }

    if (v.size() == 0)
        cout << "FRULA";
    else
        for (auto &&i : v) {
            cout << i;
        }

    return 0;
}