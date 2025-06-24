#include <iostream>
#include <string>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n;
    string list[100];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> list[i];

    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (list[j] == std::string(list[i].rbegin(), list[i].rend()))
                cout << list[i].size() << ' ' << list[i][list[i].size() / 2];

    return 0;
}