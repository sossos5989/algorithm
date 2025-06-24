#include <iostream>
#include <map>
#include <vector>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int r, c;
    cin >> r >> c;

    string s;
    vector<string> input;
    for (int i = 0; i < r; i++) {
        cin >> s;
        input.push_back(s);
    }

    map<string, int> m;
    for (int i = r - 1; i >= 0; i--) {
        for (int j = 0; j < c; j++) {
            string cache = "";
            cache += input[i][j];
            m[cache] = j;
        }
    }

    for (auto &&i : m) {
        cout << i.first << '\n';
    }

    return 0;
}