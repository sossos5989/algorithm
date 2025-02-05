#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int cache, ret;
bool used[42];

int main() {
    fastIO;
    for (int i = 0; i < 10; i++) {
        cin >> cache;
        used[cache % 42] = true;
    }
    for (int i = 0; i < 42; i++) {
        ret += used[i];
    }
    cout << ret;
    return 0;
}