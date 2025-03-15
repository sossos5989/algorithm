#include <iostream>
#include <math.h>
#include <queue>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, input;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        q;
    cin >> n;
    while (n--) {
        cin >> input;
        if (input) {
            q.push({abs(input), input});
        } else {
            if (q.empty())
                cout << "0\n";
            else {
                cout << q.top().second << "\n";
                q.pop();
            }
        }
    }
    return 0;
}