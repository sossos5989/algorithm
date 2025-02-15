#include <algorithm>
#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

pair<int, string> input[100000];

int main() {
    fastIO;
    int C;
    cin >> C;
    for (int i = 0; i < C; i++) {
        cin >> input[i].first >> input[i].second;
    }
    stable_sort(input, input + C,
                [](const pair<int, string> &a, const pair<int, string> &b) {
                    return a.first < b.first;
                });
    for (int i = 0; i < C; i++) {
        cout << input[i].first << " " << input[i].second << "\n";
    }
    return 0;
}