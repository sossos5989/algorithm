#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, x, y, q[5] = {0, 0, 0, 0, 0};
    string ret[5] = {"Q1", "Q2", "Q3", "Q4", "AXIS"};
    cin >> n;
    while (n--) {
        cin >> x >> y;
        if (x > 0 && y > 0)
            q[0]++;
        else if (x < 0 && y > 0)
            q[1]++;
        else if (x < 0 && y < 0)
            q[2]++;
        else if (x > 0 && y < 0)
            q[3]++;
        else
            q[4]++;
    }

    for (int i = 0; i < 5; i++)
        cout << ret[i] << ": " << q[i] << '\n';

    return 0;
}