#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n;
int answer[10];

int main() {
    fastIO;
    cin >> n;
    int sum = 1;
    int prev = 1;
    answer[0] = -1;

    while (n) {
        int digit = n % 10;

        for (int i = 0; i < 10; i++) {
            answer[i] += (n / 10) * sum;
        }

        for (int i = 0; i < digit; i++) {
            answer[i] += sum;
        }

        answer[digit] += prev;
        prev += digit * sum;
        n /= 10;
        sum *= 10;

        if (n) answer[0] -= sum;
    }

    for (int i = 0; i < 10; i++) {
        cout << answer[i] << " ";
    }

    return 0;
}