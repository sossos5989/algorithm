#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int H, M;

int main() {
    fastIO;
    cin >> H >> M;
    cout << (H + 24 - (M < 45)) % 24 << " " << (M + 15) % 60;
    return 0;
}