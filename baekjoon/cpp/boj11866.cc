#include <iostream>
#include <numeric>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, k;

int main() {
    fastIO;
    cin >> n >> k;
    vector<int> answer(n);
    iota(answer.begin(), answer.end(), 1); // 1 2 3 ... n까지 채웁니다.
    int cache = k - 1;
    cout << "<";
    while (n-- > 1) {
        cout << answer[cache] << ", ";
        answer.erase(answer.begin() + cache);
        cache = (cache + (k - 1)) % n;
    }
    cout << answer[0] << ">";
    return 0;
}