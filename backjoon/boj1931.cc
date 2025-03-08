#include <algorithm>
#include <iostream>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, a, b;
pair<int, int> list[100000];

int main() {
    fastIO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        list[i] = {b, a};
    }
    sort(list, list + n);
    int count = 1, lo = list[0].first;
    for (int i = 1; i < n; i++) {
        if (list[i].second >= lo) {
            count++;
            lo = list[i].first;
        }
    }
    cout << count;
    return 0;
}