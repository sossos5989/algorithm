#include <iostream>
#include <string>
#include <unordered_map>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, m;
    cin >> n >> m;
    unordered_map<string, int> sToI;
    string input, iToS[100001];
    for (int i = 1; i <= n; i++) {
        cin >> input;
        sToI[input] = i;
        iToS[i] = input;
    }
    while (m--) {
        cin >> input;
        if (input[0] >= '0' && input[0] <= '9')
            cout << iToS[stoi(input)] << "\n";
        else
            cout << sToI[input] << "\n";
    }
    return 0;
}