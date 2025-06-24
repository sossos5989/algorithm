#include <iostream>
#include <queue>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int q, v;
    cin >> q >> v;
    int size = 0;
    queue<pair<int, int>> queue;
    while (q--) {
        int a, b, c;
        cin >> a;
        if (a == 1) {
            cin >> b >> c;
            int canPush = (c < (v - size)) ? c : (v - size);
            if (canPush > 0) {
                queue.push({b, canPush});
                size += canPush;
            }
        } else if (a == 2) {
            cin >> b;
            if (size <= b) {
                while (!queue.empty()) {
                    queue.pop();
                }
                size = 0;
            } else {
                while (b) {
                    if (b >= queue.front().second) {
                        b -= queue.front().second;
                        size -= queue.front().second;
                        queue.pop();
                    } else {
                        queue.front().second -= b;
                        size -= b;
                        b = 0;
                    }
                }
            }
        } else if (a == 3) {
            if (queue.size() == 0)
                cout << "-1\n";
            else
                cout << queue.front().first << '\n';
        }
    }
    return 0;
}