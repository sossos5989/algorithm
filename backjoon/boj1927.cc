#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n;

    vector<int> minHeap;
    minHeap.reserve(n);

    while (n--) {
        cin >> x;
        if (x != 0) {
            minHeap.push_back(x);
            push_heap(minHeap.begin(), minHeap.end(), greater<int>());
        } else {
            if (minHeap.empty()) {
                cout << "0\n";
            } else {
                cout << minHeap.front() << "\n";
                pop_heap(minHeap.begin(), minHeap.end(), greater<int>());
                minHeap.pop_back();
            }
        }
    }
    return 0;
}