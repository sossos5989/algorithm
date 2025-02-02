#include <iostream>
#include <numeric>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, k;

int main() {
    fastIO;
    int C;
    cin >> C;
    while (C--) {
        cin >> n >> k;
        vector<int> answer(n);
        iota(answer.begin(), answer.end(), 1); // 1 2 3 ... n까지 채웁니다.
        int cache = 0;
        while (n-- > 2) {
            answer.erase(answer.begin() + cache);
            cache = (cache + (k - 1)) % n;
        }
        for (int &i : answer) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}