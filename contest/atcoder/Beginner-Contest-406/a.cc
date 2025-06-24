#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n;
    cin >> n;
    if (200 <= n && n < 300)
        cout << "Success";
    else
        cout << "Failure";
    return 0;
}