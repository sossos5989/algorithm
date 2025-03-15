#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n;

int main() {
    fastIO;
    cin >> n;
    cout << (!(n % 4) && n % 100 || !(n % 400)) << endl;
    return 0;
}