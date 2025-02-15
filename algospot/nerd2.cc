#include <iostream>
#include <map>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

map<int, int> tree;

bool isDominated(int p, int q) {
    map<int, int>::iterator it = tree.lower_bound(p);
    if (it == tree.end()) return false;
    return q < it->second;
}

void removeDominated(int p, int q) {
    map<int, int>::iterator it = tree.lower_bound(p);
    if (it == tree.begin()) return;
    --it;
    while (1) {
        if (it->second > q) break; // 지배되지 않아서 종료
        if (it == tree.begin()) {
            tree.erase(it);
            break; // 시작에 도착하면 종료
        } else {
            map<int, int>::iterator jt = it;
            jt--;
            tree.erase(it);
            it = jt; // 지움
        }
    }
}

int registered(int p, int q) {
    if (isDominated(p, q)) return tree.size();
    removeDominated(p, q);
    tree[p] = q;
    return tree.size();
}

int main() {
    fastIO;
    int C, n;
    cin >> C;
    while (C--) {
        cin >> n;
        tree.clear();
        int sum = 0, p, q;
        for (int i = 0; i < n; i++) {
            cin >> p >> q;
            sum += registered(p, q);
        }
        cout << sum << "\n";
    }
    return 0;
}