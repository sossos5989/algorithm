#include <algorithm>
#include <iostream>
#include <math.h>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, sum, list[300000];

int main() {
    fastIO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }
    sort(list, list + n);
    int cut = (int)round(0.15 * n);
    for (int i = cut; i < n - cut; i++) {
        sum += list[i];
    }
    cout << (n ? (int)round((double)sum / (n - 2 * cut)) : 0);
    return 0;
} // counting sort를 이용하면, 더 빠르게 풀 수 있다.