#include <iostream>
#include <set>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, input;
    cin >> n;
    set<int> s;
    while (n--) {
        cin >> input;
        s.insert(input);
    }

    cin >> n;
    while (n--) {
        cin >> input;
        cout << bool(s.find(input) != s.end()) << ' ';
    }

    return 0;
}