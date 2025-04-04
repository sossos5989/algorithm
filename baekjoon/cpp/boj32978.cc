#include <iostream>
#include <set>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

string list[1000];
int main() {
    fastIO;
    int n;
    string s;
    cin >> n;
    set<string> s1;
    for (int i = 0; i < n; i++) {
        cin >> s;
        s1.emplace(s);
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> s;
        s1.erase(s);
    }

    cout << *s1.begin();

    return 0;
}