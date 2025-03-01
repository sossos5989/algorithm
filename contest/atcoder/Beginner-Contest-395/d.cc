#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int pigeon[1000001];
    vector<map<int, int>> nest(1000001);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        pigeon[i] = i;
        nest[i][i] = i;
    }

    int type, a, b;
    for (int i = 0; i < q; i++) {
        cin >> type;
        if (type == 1) {
            cin >> a >> b;
            int k = pigeon[a];
            pigeon[a] = b;
            nest[k].erase(nest[k].find(a));
            nest[b][a] = a;
        } else if (type == 2) {
            cin >> a >> b;
            swap(nest[a], nest[b]);
            for (auto &i : nest[a]) {
                pigeon[i.first] = a;
            }
            for (auto &i : nest[b]) {
                pigeon[i.first] = b;
            }
        } else if (type == 3) {
            cin >> a;
            cout << pigeon[a] << "\n";
        }
    }
    return 0;
}