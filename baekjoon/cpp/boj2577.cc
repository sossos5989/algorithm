#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int a, b, c;
int answer[10];

int main() {
    fastIO;
    cin >> a >> b >> c;
    int ret = a * b * c;
    while (ret) {
        answer[ret % 10]++;
        ret /= 10;
    }
    for (int i = 0; i < 10; i++) {
        cout << answer[i] << "\n";
    }

    return 0;
}