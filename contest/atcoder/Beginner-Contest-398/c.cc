#include <iostream>
#include <map>
#include <unordered_map>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    map<int, int> m;
    unordered_map<int, int> mapping;
    int n, input;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> input;
        auto it = m.find(input);
        if (m.end() != it) {
            m[input]++;
        } else {
            m[input] = 1;
            mapping[input] = i;
        }
    }

    int ans = -1;
    for (auto it = m.begin(); it != m.end(); it++) {
        if (it->second == 1) ans = mapping[it->first];
    }
    cout << ans;
    return 0;
}