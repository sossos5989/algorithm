#include <iostream>
#include <cstring>
#include <limits>
#include <cmath>

using namespace std;

int n, m;

double cache[3000][1001];

double function(int climbed, int days) {
    if (days == m) return climbed >= n ? 1 : 0;
    double& ret = cache[climbed][days];
    if (!std::isnan(ret)) return ret;
    return ret = 0.5 * function(climbed+1, days+1) + 1.5 * function(climbed+2, days+1);
}

int main() {
    int repeat;
    cin >> repeat;
    while (repeat-- > 0) {
        fill(&cache[0][0], &cache[0][0] + 3000 * 1001, NAN);
        cin >> n >> m;
        double answer = function(0, 0) / pow(2, m);
        cout << fixed;
        cout.precision(10);
        cout << answer << "\n";
    }
    return 0;
}
