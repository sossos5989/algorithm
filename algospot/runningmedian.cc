#include <iostream>
#include <queue>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, a, b;

int main() {
    fastIO;
    int C;
    cin >> C;
    while (C--) {
        cin >> n >> a >> b;
        priority_queue<int, vector<int>, less<int>> max_heap;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int rng = 1983, sum = 0;
        while (n--) {
            if (max_heap.size() == min_heap.size())
                max_heap.push(rng);
            else
                min_heap.push(rng);
            if (!min_heap.empty() && !max_heap.empty() &&
                min_heap.top() < max_heap.top()) {
                int x = min_heap.top(), y = max_heap.top();
                min_heap.pop();
                max_heap.pop();
                min_heap.push(y);
                max_heap.push(x);
            }
            rng = (rng * (long long)a + b) % 20090711;
            sum += max_heap.top();
            sum %= 20090711;
        }
        cout << sum << "\n";
    }
    return 0;
}