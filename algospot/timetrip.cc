#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n;
    cin >> n;
    vector<string> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    char cache = 0;
    int normal = 0, blindless = 0;
    for (int i = 0; i < n; i++) {
        if (input[0][i] != cache) {
            normal++;
            cache = input[0][i];
        }
    }
    cout << normal << " " << blindless;
    return 0;
}