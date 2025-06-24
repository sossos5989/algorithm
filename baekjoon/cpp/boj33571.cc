#include <iostream>

using namespace std;

char s[1001];
int cnt, holes[128];

int main() {
    holes['A'] = holes['a'] = holes['b'] = holes['D'] = holes['d'] =
        holes['e'] = holes['g'] = holes['O'] = holes['o'] = holes['P'] =
            holes['p'] = holes['Q'] = holes['q'] = holes['R'] = holes['@'] = 1;
    holes['B'] = 2;
    cin.getline(s, 1001);
    for (char &c : s)
        cnt += holes[c];
    cout << cnt;
    return 0;
}