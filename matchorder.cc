#include <algorithm>
#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

// 가성비 승리를 구현하자.
int main() {
    fastIO;
    int repeat;
    cin >> repeat;
    while (repeat--) {
        int n;
        cin >> n;
        vector<int> russia(n), korea(n);
        for (int i = 0; i < n; i++) {
            cin >> russia[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> korea[i];
        }

        sort(russia.begin(), russia.end());
        sort(korea.begin(), korea.end());

        int ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < korea.size(); j++) {
                if (russia[i] <= korea[j]) {
                    ret++;
                    korea.erase(korea.begin() + j);
                    break;
                }
            }
        }
        cout << ret << endl;
    }
    return 0;
}