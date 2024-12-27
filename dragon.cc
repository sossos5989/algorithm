#include <iostream>
#include <string>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, p, l;
const int MAX = 1000000000 + 1;

int length[51];
void precalc() {
    length[0] = 1;
    for (int i = 1; i <= 50; i++) {
        length[i] = min(MAX, length[i-1] * 2 + 2);
    }
    
}

char expand(const string& dragonCurve, int generations, int skip) {
    if (generations == 0) return dragonCurve[skip];

    for (int i = 0; i < dragonCurve.size(); i++) {
        if (dragonCurve[i] == 'X' || dragonCurve[i] == 'Y') {
            if (skip >= length[generations]) {
                skip -= length[generations];
            } else if (dragonCurve[i] == 'X') {
                return expand("X+YF", generations-1, skip);
            } else {
                return expand("FX-Y", generations-1, skip);
            }
        } else if (skip > 0) {
            --skip;
        } else {
            return dragonCurve[i];
        }
    }
    return '#';
}

int main() {
    fastIO;
    int repeat;
    cin >> repeat;
    while (repeat--) {
        cin >> n >> p >> l;
        int i = -1;
        precalc();
        while(l--) {
            cout << expand("FX", n, p + i++);
        }
        cout << endl;
    }
    return 0;
}