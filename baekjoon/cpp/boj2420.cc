#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

long n, m;
int main() {
    fastIO;
    cin >> n >> m;
    cout << (n > m ? n - m : m - n);
    return 0;
}