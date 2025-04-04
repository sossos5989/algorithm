#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    string s;
    cin >> s;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < s.size() - 2; i++) {
        string now = s.substr(i, 3);
        if (now == "JOI") cnt1++;
        if (now == "IOI") cnt2++;
    }
    cout << cnt1 << '\n' << cnt2;
    return 0;
}