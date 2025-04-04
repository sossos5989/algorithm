#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int input, sum = 0;
    for (int i = 0; i < 5; i++) {
        cin >> input;
        if (input < 40) input = 40;
        sum += input;
    }
    cout << sum / 5;
    return 0;
}