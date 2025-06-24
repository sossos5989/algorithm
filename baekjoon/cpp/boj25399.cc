#include <iostream>
#include <map>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

map<long long, int> m;

int main() {
    fastIO;

    for (int i = 1; i <= 1000000; i++) {
        m[i ^ 2] = 1;
    }

    long long n;
    cin >> n;
    cout << m[n];
    return 0;
}