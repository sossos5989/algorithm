#include <iostream>
#include <unordered_map>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, m;
    cin >> n >> m;
    unordered_map<string, string> mapping;
    string link, pwd;
    for (int i = 0; i < n; i++) {
        cin >> link >> pwd;
        mapping[link] = pwd;
    }
    for (int i = 0; i < m; i++) {
        cin >> link;
        cout << mapping[link] << "\n";
    }
    return 0;
}