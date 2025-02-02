#include <algorithm>
#include <iostream>
using namespace std;

// 각 초밥의 선호도(pref)는 최대 20입니다.
// 초밥 종류의 수(n)는 최대 20입니다.
//"따라서, 중복 없이 얻을 수 있는 최대 선호도 합은 20 (최대 선호도) * 20 (최대
// 종류 수) = 400입니다." 그것을 초과하면 무조건 중복이 있음요.

int dp[401];
int main() {
    int cs;
    cin >> cs;
    while (cs--) {
        int ma = 1, mb = 0;
        int n, m;
        cin >> n >> m;
        m /= 100;
        for (int i = 1; i < 401; ++i)
            dp[i] = 1e9;
        while (n--) {
            int price, pref;
            cin >> price >> pref;
            price /= 100;
            for (int i = pref; i < 401; ++i)
                dp[i] = min(dp[i], dp[i - pref] + price);
            // ex: 만족도 103 이 되기 위한 최소가격
            // dp[103] = min(dp[103], dp[103 - 12] + price	// (만족도가 12
            // 인것과 그것의 가격)
            if (ma * pref > mb * price) {
                ma = price;
                mb = pref;
            }
        }
        int r = 0;
        for (int i = 0; i < 401; ++i)
            if (dp[i] <= m) r = max(r, i + (m - dp[i]) / ma * mb);
        cout << r << '\n';
    }
    return 0;
}