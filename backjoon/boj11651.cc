#include <algorithm>
#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n;
    cin >> n;
    pair<int, int> coord[100000];
    for (int i = 0; i < n; i++) {
        cin >> coord[i].second >> coord[i].first;
    }
    sort(coord, coord + n);
    for (int i = 0; i < n; i++) {
        cout << coord[i].second << " " << coord[i].first << "\n";
    }
    return 0;
}