#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int list[4];

int main() {
    fastIO;
    int n, x;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s >> x;
        if (s == "STRAWBERRY")
            list[0] += x;
        else if (s == "BANANA")
            list[1] += x;
        else if (s == "LIME")
            list[2] += x;
        else
            list[3] += x;
    }
    cout << (list[0] == 5 || list[1] == 5 || list[2] == 5 || list[3] == 5
                 ? "YES"
                 : "NO");
    return 0;
}