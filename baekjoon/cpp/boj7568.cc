#include <algorithm>
#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, answer[100];
struct point {
    int x, y, index;
} coord[100];

int main() {
    fastIO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> coord[i].x >> coord[i].y;
    }
    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = 0; j < n; j++) {
            if (coord[i].x < coord[j].x && coord[i].y < coord[j].y) count++;
        }
        answer[i] = count;
    }
    for (int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }
    return 0;
}