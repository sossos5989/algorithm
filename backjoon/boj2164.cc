#include <iostream>
#include <numeric>
#include <queue>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, x, y;
queue<int> A;

int main() {
    fastIO;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        A.push(i);
    }
    while (A.size() > 1) {
        A.pop();
        A.push(A.front());
        A.pop();
    }
    cout << A.front();
    return 0;
}