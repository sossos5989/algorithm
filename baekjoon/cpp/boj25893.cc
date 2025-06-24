#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int list[26];
int main() {
    fastIO;
    int n;
    string s;
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        list[s[i] - 'a']++;
    }

    int ans = list['u' - 'a'];
    ans = min(ans, list['o' - 'a']);
    ans = min(ans, list['s' - 'a']);
    ans = min(ans, list['p' - 'a']);
    ans = min(ans, list['c' - 'a']);

    cout << ans;
    return 0;
}