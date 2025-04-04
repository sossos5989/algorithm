#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int list[400002];
vector<int> number[200002];
int main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            number[i].clear();
        }

        for (int i = 0; i < 2 * n; i++) {
            cin >> list[i];
            number[list[i]].push_back(i);
        }

        set<pair<int, int>> answers;
        for (int i = 0; i + 1 < 2 * n; i++) {
            int a = list[i], b = list[i + 1];
            // if (a == b) continue;
            if (number[a][0] + 1 == number[a][1]) continue;
            if (number[b][0] + 1 == number[b][1]) continue;
            vector<int> v{number[a][0], number[a][1], number[b][0],
                          number[b][1]};
            sort(begin(v), end(v));
            if (v[0] + 1 == v[1] and v[2] + 1 == v[3]) {
                answers.insert(minmax(a, b));
            }
        }

        cout << answers.size() << '\n';
    }
    return 0;
}