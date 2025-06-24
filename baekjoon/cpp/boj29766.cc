#include <iostream>
#include <string>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.size() - 3; i++)
        if (s.substr(i, 4) == "DKSH") cnt++;
    cout << cnt;
    return 0;
}