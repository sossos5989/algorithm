#include <iostream>
#include <map>
#include <queue>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int t, k, n;
    char c;
    cin >> t;
    while (t--) {
        priority_queue<int> max_heap;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        map<int, int> list;
        cin >> k;
        while (k--) {
            cin >> c >> n;
            if (c == 'I') {
                max_heap.push(n);
                min_heap.push(n);
                list[n]++;
            } else {
                if (list.empty()) continue;
                if (n == 1) {
                    while (!max_heap.empty() &&
                           list.find(max_heap.top()) == list.end()) {
                        max_heap.pop();
                    }
                    if (max_heap.empty()) continue;
                    int key = max_heap.top();
                    max_heap.pop();
                    if (--list[key] == 0) list.erase(key);
                } else {
                    while (!min_heap.empty() &&
                           list.find(min_heap.top()) == list.end()) {
                        min_heap.pop();
                    }
                    if (min_heap.empty()) continue;
                    int key = min_heap.top();
                    min_heap.pop();
                    if (--list[key] == 0) list.erase(key);
                }
            }
        }
        if (list.empty())
            cout << "EMPTY\n";
        else {
            while (!max_heap.empty() &&
                   list.find(max_heap.top()) == list.end()) {
                max_heap.pop();
            }
            while (!min_heap.empty() &&
                   list.find(min_heap.top()) == list.end()) {
                min_heap.pop();
            }
            if (max_heap.empty() || min_heap.empty())
                cout << "EMPTY\n";
            else
                cout << max_heap.top() << " " << min_heap.top() << "\n";
        }
    }
    return 0;
}
