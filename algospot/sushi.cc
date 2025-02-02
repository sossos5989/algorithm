#include <cstring>
#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;
int n, m;
int price[20], preference[20];

int DP[201];
int sushi() {
    int ret = 0;
    DP[0] = 0;
    for (int budget = 1; budget <= m; budget++) {
        int cand = 0;
        for (int i = 0; i < n; i++) {
            if (budget >= price[i]) {
                cand = max(cand, DP[(budget - price[i]) % 201] + preference[i]);
            }
            DP[budget % 201] = cand;
            ret = max(ret, cand);
        }
    }
    return ret;
}

int main() {
    fastIO;
    int repeat;
    cin >> repeat;
    while (repeat--) {
        cin >> n >> m;
        m /= 100;
        for (int i = 0; i < n; i++) {
            cin >> price[i] >> preference[i];
            price[i] /= 100;
        }
        cout << sushi() << endl;
    }
    return 0;
}