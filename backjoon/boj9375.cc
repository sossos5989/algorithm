#include <iostream>
#include <unordered_map>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int T, n;
    cin >> T;
    while (T--) {
        string input, wear[30] = {""};
        int ptr = 0, num[30] = {0};
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> input >> input;
            bool exist = false;
            for (int j = 0; j < ptr; j++) {
                if (wear[j] == input) {
                    num[j]++;
                    exist = true;
                    break;
                }
            }
            if (!exist) {
                wear[ptr] = input;
                num[ptr]++;
                ptr++;
            }
        }
        int ret = 1;
        for (int i = 0; i < ptr; i++) {
            ret *= num[i] + 1;
        }
        cout << ret - 1 << "\n";
    }
    return 0;
}