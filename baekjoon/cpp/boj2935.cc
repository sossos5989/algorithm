#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    string a, c, b, ans;
    cin >> a >> c >> b;
    if (c == "+") {
        string cache(max(a.size(), b.size()), '0');
        ans = cache;
        ans[cache.size() - a.size()]++;
        ans[cache.size() - b.size()]++;
    }
    if (c == "*") {
        string cache(a.size() + b.size() - 2, '0');
        ans += '1';
        ans += cache;
    }
    cout << ans;
    return 0;
}