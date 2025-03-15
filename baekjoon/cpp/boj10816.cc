#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m, input, A[20000001], B[20000001];
int main() {
    fastIO;
    cin >> n;
    while (n--) {
        cin >> input;
        A[input + 10000000]++;
    }
    cin >> m;
    while (m--) {
        cin >> input;
        cout << A[input + 10000000] << " ";
    }
    return 0;
}