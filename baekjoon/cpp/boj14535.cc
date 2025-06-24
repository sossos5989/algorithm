#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n;
    string month[13] = {"",    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    cin >> n;
    for (int i = 1; n; i++) {
        int d, m, y, list[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        while (n--) {
            cin >> d >> m >> y;
            list[m]++;
        }

        cout << "Case #" << i << ":\n";
        for (int j = 1; j < 13; j++)
            cout << month[j] << ":" << string(list[j], '*') << '\n';

        cin >> n;
    }

    return 0;
}