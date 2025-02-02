#include <algorithm>
#include <iostream>
#include <queue>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

// vector에서 priority queue로 개선한 모습입니다.
int main() {
    fastIO;
    int repeat;
    cin >> repeat;
    while (repeat--) {
        int n;
        cin >> n;
        priority_queue<int, vector<int>, std::greater<int>> minHeap;
        for (int i = 0; i < n; i++) {
            int length;
            cin >> length;
            minHeap.push(length);
        }

        long long totalCost = 0;
        while (minHeap.size() > 1) {
            int first = minHeap.top();
            minHeap.pop();
            int second = minHeap.top();
            minHeap.pop();
            int combined = first + second;
            totalCost += combined;
            minHeap.push(combined);
        }
        cout << totalCost << "\n";
    }
    return 0;
}