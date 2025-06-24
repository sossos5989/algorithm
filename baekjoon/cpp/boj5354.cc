#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

void print(int x) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++)
            cout << (i == 0 || j == 0 || i == x - 1 || j == x - 1 ? '#' : 'J');
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    fastIO;
    int n, input;
    cin >> n;
    while (n--) {
        cin >> input;
        print(input);
    }
    return 0;
}