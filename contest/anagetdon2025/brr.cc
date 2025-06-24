#include <iostream>
#include <math.h>
#include <string>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    string s, target;
    cin >> s >> target;
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    int th = stoi(target.substr(0, 2));
    int tm = stoi(target.substr(3, 2));

    int ans = 100000;

    if (m < tm) {
        int mingap = abs(tm - m);
        int hourgap = abs(h - th);
        ans = min(ans, hourgap + mingap);
        ans = min(ans, (24 - hourgap) + mingap);
        ans = min(ans, abs((h - th + 23) % 24) + (60 - mingap));
        ans = min(ans, (24 - abs(h - th + 23) % 24) + (60 - mingap));
    } else if (m > tm) {
        int mingap = abs(tm - m);
        int hourgap = abs(h - th);
        ans = min(ans, abs(th - (h + 1)) % 24 + (60 - mingap));
        ans = min(ans, (24 - abs(th - (h + 1)) % 24) + (60 - mingap));
        ans = min(ans, abs(h - th) + mingap);
        ans = min(ans, (24 - abs(h - th)) + mingap);
    } else {
        ans = min(abs(h - th), 24 - abs(h - th));
    }
    cout << ans;
    return 0;
}