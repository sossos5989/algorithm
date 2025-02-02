#include <algorithm>
#include <array>
#include <cstring>
#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

string e, digit;
int m;

int DP[1 << 14][20][2];
int count(int index, int taken, int mod, int less) {
    if (index == e.size()) return (less && mod == 0) ? 1 : 0;
    int &ret = DP[taken][mod][less];
    if (ret != -1) return ret;
    ret = 0;
    for (int next = 0; next < e.size(); next++) {
        if (taken & (1 << next)) continue; // 현재 자리수가 사용되었는지 검사
        if (!less && e[index] < digit[next]) continue;
        if (next && digit[next - 1] == digit[next] &&
            (taken & (1 << (next - 1))) == 0)
            continue;
        int nextTaken = taken | (1 << next);
        int nextMod = (mod * 10 + digit[next] - '0') % m;
        int nextLess = less || e[index] > digit[next];
        ret += count(index + 1, nextTaken, nextMod, nextLess);
        ret %= 1000000007;
    }
    return ret;
}

int main() {
    fastIO;
    int repeat;
    cin >> repeat;
    while (repeat-- > 0) {
        cin >> e >> m;
        digit = e;
        sort(digit.begin(), digit.end());
        memset(DP, -1, sizeof(DP));
        cout << count(0, 0, 0, 0) << endl;
    }
    return 0;
}