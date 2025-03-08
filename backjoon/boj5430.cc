#include <iostream>
#include <string>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, list[100010];
string p, x_input;

int main() {
    fastIO;
    int t;
    cin >> t;
    while (t--) {
        cin >> p >> n >> x_input;
        int prev = 1, count = 0, i = 1;
        while (1 && n > 0) {
            if (count == n - 1) {
                list[count] =
                    stoi(x_input.substr(i, x_input.size() - 1 - prev));
                break;
            }
            if (x_input[i] == ',') {
                list[count] = stoi(x_input.substr(prev, i - prev));
                count++;
                prev = i + 1;
            }
            i++;
        }

        int lo = 0, hi = n - 1;
        bool isReversed = false, isError = false;
        for (char &c : p) {
            if (c == 'R') {
                isReversed = !isReversed;
            } else {
                if (isReversed) {
                    hi--;
                } else {
                    lo++;
                }

                if (lo - 1 > hi) {
                    isError = true;
                    break;
                }
            }
        }

        if (isError)
            cout << "error\n";
        else {
            cout << "[";
            if (isReversed) {
                while (hi > lo) {
                    cout << list[hi--];
                    cout << ',';
                }
                if (hi == lo) cout << list[hi];
                cout << "]\n";
            } else {
                while (hi > lo) {
                    cout << list[lo++];
                    cout << ',';
                }
                if (hi == lo) cout << list[lo];
                cout << "]\n";
            }
        }
        // cout << answer;
    }
    return 0;
} // deque를 이용하면 더 쉽게 구현이 가능하다.