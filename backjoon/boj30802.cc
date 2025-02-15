#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, ssize[6], t, p, shirt;

int main() {
    fastIO;
    cin >> n;
    for (int i = 0; i < 6; i++) {
        cin >> ssize[i];
    }
    cin >> t >> p;
    for (int i = 0; i < 6; i++) {
        shirt += (ssize[i] + t - 1) / t;
    }
    cout << shirt << "\n" << n / p << " " << n % p;
    return 0;
}