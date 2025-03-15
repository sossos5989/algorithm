#include <iostream>
#include <math.h>
#include <vector>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n;
    double list[100];
    cin >> n;

    vector<double> a;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cand = (double)(list[j] - list[i]) / (double)(j - i);
            a.push_back(cand);
        }
    }

    bool b;
    for (int start = 0; start < n; start++) {
        list[start] if (floor(list[i] + slope * i) != list[i]) b = false;
    }

    cout << (b ? "pass" : "fail");
    return 0;
}