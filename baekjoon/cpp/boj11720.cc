#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, sum;
string s;
int main() {
    fastIO;
    cin >> n >> s;
    for (int i = 0; i < s.size(); i++) {
        sum += s[i] - '0';
    }
    cout << sum;
    return 0;
}