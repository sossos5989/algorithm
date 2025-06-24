#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n;
    string ans;
    cin >> n;
    int state = 0, errCnt = 0; // login
    while (n--) {
        cin >> ans;
        if (ans == "login") {
            state = 1;
        } else if (ans == "logout") {
            state = 0;
        } else if (ans == "private") {
            if (state == 0) errCnt++;
        }
    }
    cout << errCnt;
    return 0;
}