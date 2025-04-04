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
                min_heap.push(n);
                max_heap.push(n);
                int size = 1;
                auto it = list.find(n);
                if (it != list.end()) {
                    size += it->second;
                    list.erase(it);
                }
                list[n] = size;
            } else {
                if (list.empty()) continue;

                if (n == 1) {
                    auto it = list.find(max_heap.top());
                    while (it == list.end()) {
                        max_heap.pop();
                        it = list.find(max_heap.top());
                    }
                    if (list.empty()) continue;
                    int cache = it->first;
                    int size = it->second;
                    list.erase(it);
                    if (size - 1 > 0) list[cache] = size - 1;
                    max_heap.pop();
                } else {
                    auto it = list.find(min_heap.top());
                    while (it == list.end()) {
                        min_heap.pop();
                        it = list.find(min_heap.top());
                    }
                    if (list.empty()) continue;
                    int cache = it->first;
                    int size = it->second;
                    list.erase(it);
                    if (size - 1 > 0) list[cache] = size - 1;
                    min_heap.pop();
                }
            }
        }
        if (list.empty())
            cout << "EMPTY\n";
        else {
            auto it = list.find(max_heap.top());
            while (it == list.end()) {
                max_heap.pop();
                it = list.find(max_heap.top());
            }
            it = list.find(min_heap.top());
            while (it == list.end()) {
                min_heap.pop();
                it = list.find(min_heap.top());
            }
            cout << max_heap.top() << " " << min_heap.top() << "\n";
        }
    }
    return 0;
}