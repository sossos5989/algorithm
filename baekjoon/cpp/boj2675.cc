#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int r;
string p;
int main() {
    fastIO;
    int C;
    cin >> C;
    while (C--) {
        cin >> r >> p;
        for (int i = 0; i < p.size(); i++) {
            cout << string(r, p[i]);
        }
        cout << "\n";
    }
    return 0;
}