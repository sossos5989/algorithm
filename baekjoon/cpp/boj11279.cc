#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n;

    vector<int> maxHeap;
    maxHeap.reserve(n);

    while (n--) {
        cin >> x;
        if (x != 0) {
            maxHeap.push_back(x);
            push_heap(maxHeap.begin(), maxHeap.end());
        } else {
            if (maxHeap.empty()) {
                cout << "0\n";
            } else {
                cout << maxHeap.front() << "\n";
                pop_heap(maxHeap.begin(), maxHeap.end());
                maxHeap.pop_back();
            }
        }
    }
    return 0;
}