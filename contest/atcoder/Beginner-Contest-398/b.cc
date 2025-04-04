#include <algorithm>
#include <iostream>
#include <vector>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int cnt[14];

int main() {
    fastIO;
    int input;
    for (int i = 0; i < 7; i++) {
        cin >> input;
        cnt[input]++;
    }

    vector<int> list;
    for (int i = 1; i < 14; i++) {
        list.push_back(cnt[i]);
    }
    sort(list.begin(), list.end(), greater<int>());

    cout << (list[0] >= 3 && list[1] >= 2 ? "Yes" : "No");
    return 0;
}