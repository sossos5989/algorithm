#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

bool list[30];
int cache;

int main() {
    fastIO;
    for (int i = 0; i < 28; i++) {
        cin >> cache;
        list[cache - 1] = true;
    }
    for (int i = 0; i < 30; i++) {
        if (!list[i]) cout << i + 1 << "\n";
    }
    return 0;
}