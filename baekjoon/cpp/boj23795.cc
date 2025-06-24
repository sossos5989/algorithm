#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int input = 0, sum = 0;
    while (1) {
        cin >> input;
        if (input == -1) break;
        sum += input;
    }
    cout << sum;
    return 0;
}