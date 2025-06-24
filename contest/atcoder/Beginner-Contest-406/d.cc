#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, k;
    string s;
    cin >> n >> k >> s;

    for (int i = 0; i < n; i++)
        if (s[i] == 'o') {
            if (i != 0) s[i - 1] = '.';
            if (i + 1 != n) s[i + 1] = '.';
            k--;
        }

    int idx = -1, size = 0;
    vector<pair<int, int>> v; // idx, size;
    for (int i = 0; i < n; i++)
        if (s[i] == '?') {
            size++;
        } else {
            if (size > 0) v.push_back({idx + 1, size});
            idx = i;
            size = 0;
        }

    if (size > 0) v.push_back({idx + 1, size});

    int sum = 0;
    for (auto &i : v) {
        sum += (i.second + 1) / 2;
    }

    if (k == 0) {
        for (auto &&i : v)
            for (int p = i.first; p < i.first + i.second; p++)
                s[p] = '.';
    } else if (sum == k) {
        for (auto &&i : v)
            if (i.second % 2 == 1)
                for (int p = i.first; p < i.first + i.second; p++)
                    s[p] = ((p - i.first) % 2 == 0 ? 'o' : '.');
    }

    cout << s;
    return 0;
}