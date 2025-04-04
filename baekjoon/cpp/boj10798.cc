#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    vector<string> list(5);
    for (int i = 0; i < 5; i++)
        cin >> list[i];

    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 5; j++)
            if (list[j].size() > i) cout << list[j][i];

    return 0;
}