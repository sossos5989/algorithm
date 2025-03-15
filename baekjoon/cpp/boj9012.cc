#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n;
string input;

int main() {
    fastIO;
    cin >> n;
    while (n--) {
        cin >> input;
        int vps = 0;
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '(')
                vps++;
            else
                vps--;
            if (vps < 0) break;
        }
        cout << (vps ? "NO\n" : "YES\n");
    }
    return 0;
}