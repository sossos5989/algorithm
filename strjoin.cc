#include <algorithm>
#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int repeat;
    cin >> repeat;
    while (repeat--) {
        int n;
        cin >> n;
        vector<int> list(n);
        for (int i = 0; i < n; i++) {
            cin >> list[i];
        }
        sort(list.begin(), list.end());
        int ret = 0;
        while (--n) {
            int cache = list[0] + list[1];
            ret += cache;
            list.erase(list.begin(), list.begin() + 2);
            list.push_back(cache);
            sort(list.begin(), list.end());
        }

        cout << ret << endl;
    }
    return 0;
}