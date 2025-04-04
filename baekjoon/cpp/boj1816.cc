#include <cstring>
#include <iostream>
#include <vector>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n;
    long long s;
    vector<int> prime;

    bool used[1000001];
    for (int i = 2; i <= 1000000; i++) {
        if (used[i] == 0) prime.push_back(i);
        for (auto &j : prime) {
            if (i * j > 1000000) break;
            used[i * j] = 1;
            if (i % j == 0) break;
        }
    }

    cin >> n;
    while (n--) {
        cin >> s;
        bool b = true;
        for (int &i : prime) {
            if (s % i == 0) {
                b = false;
                break;
            }
        }
        cout << (b ? "YES\n" : "NO\n");
    }
    return 0;
}