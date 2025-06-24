#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 0, uppercase = 0;
    for (int i = 1; i < s.size(); i++)
        if (s[i] >= 'A' && s[i] <= 'Z') {
            ans += ((4 - i + uppercase) % 4) % 4;
            uppercase = i;
        }

    cout << ans;
    return 0;
}