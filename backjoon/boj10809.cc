#include <cstring>
#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

string input;
int answer[26];

int main() {
    fastIO;
    cin >> input;
    memset(answer, -1, sizeof(answer));
    for (int i = 0; i < input.size(); i++) {
        int &cache = answer[input[i] - 'a'];
        if (cache == -1) cache = i;
    }
    for (int i = 0; i < 26; i++) {
        cout << answer[i] << " ";
    }
    return 0;
}