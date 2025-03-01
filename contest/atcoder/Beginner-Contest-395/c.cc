#include <cstring>
#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, cache;
    cin >> n;
    int length[1000001], prev[1000001];
    for (int i = 1; i < 1000001; i++) {
        length[i] = prev[i] = 1e9;
    }

    for (int i = 0; i < n; i++) {
        cin >> cache;
        if (prev[cache] != 1e9) {
            int cand = i - prev[cache] + 1;
            if (length[cache] > cand) length[cache] = cand;
        }
        prev[cache] = i;
    }
    int min = 1e9;
    for (int i = 1; i < 1000001; i++) {
        if (min > length[i] && length[i] != -1) min = length[i];
    }
    cout << (min == 1e9 ? -1 : min);
    return 0;
}