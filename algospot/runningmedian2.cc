#include <iostream>
#include <queue>

#define MOD 20090711
#define BEGIN 1983

using namespace std;

long solve(int N, int a, int b) {
    long n = BEGIN, sum = BEGIN, median;
    priority_queue<int> lower;                            // Max-heap
    priority_queue<int, vector<int>, greater<int>> upper; // Min-heap
    lower.push(n);
    for (int i = 1; i < N; i++) {
        n = (n * a + b) % MOD;
        if (n < lower.top()) {
            lower.push(n);
            if (lower.size() > upper.size() + 1) {
                upper.push(lower.top());
                lower.pop();
            }
        } else {
            upper.push(n);
            if (upper.size() > lower.size() + 1) {
                lower.push(upper.top());
                upper.pop();
            }
        }
        median = lower.size() < upper.size() ? upper.top() : lower.top();
        sum = (sum + median) % MOD;
    }
    return sum;
}

int main() {
    int C, N;
    long a, b;
    cin >> C;
    while (C--) {
        cin >> N >> a >> b;
        cout << solve(N, a, b) << endl;
    }
    return 0;
} // 인상적인 코드를 변형했다.