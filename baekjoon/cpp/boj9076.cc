#include <algorithm>
#include <iostream>
#include <vector>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int t;
    cin >> t;
    vector<int> v(5);
    while (t--) {
        for (auto &x : v)
            cin >> x;

        sort(v.begin(), v.end());

        if (v[3] - v[1] >= 4)
            cout << "KIN\n";
        else
            cout << v[1] + v[2] + v[3] << '\n';
    }
    return 0;
}