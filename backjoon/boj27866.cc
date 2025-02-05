#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int i;
string s;

int main() {
    fastIO;
    cin >> s >> i;
    cout << s[i - 1];
    return 0;
}