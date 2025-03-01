#include <cstring>
#include <iostream>
#include <queue>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

inline int get(int mask, int index) { return (mask >> (index * 2)) & 3; }

inline int set(int mask, int index, int value) {
    return (mask & ~(3 << (index * 2))) | (value << (index * 2));
}

int n, startState = 0, endState;
int visited[1 << 24], result = 16777215;

int bfs() {
    memset(visited, 0, sizeof(int) * (1 << (2 * n)));
    queue<int> q;
    q.push(startState);
    q.push(endState);
    visited[startState] = 1;
    visited[endState] = -1;

    while (!q.empty()) {
        int mask = q.front();
        q.pop();
        int top[4] = {20, 20, 20, 20};
        for (int i = n - 1; i >= 0; i--) {
            top[get(mask, i)] = i;
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (top[i] != 20 && i != j && top[i] < top[j]) {
                    int new_mask = set(mask, top[i], j);
                    if (visited[new_mask] == 0) {
                        q.push(new_mask);
                        if (visited[mask] > 0)
                            visited[new_mask] = visited[mask] + 1;
                        else
                            visited[new_mask] = visited[mask] - 1;
                    } else if (visited[new_mask] > 0 && visited[mask] < 0) {
                        return visited[new_mask] - visited[mask] - 1;
                    } else if (visited[new_mask] < 0 && visited[mask] > 0) {
                        return -visited[new_mask] + visited[mask] - 1;
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    fastIO;
    int C;
    cin >> C;
    while (C--) {
        int repeat, input;
        cin >> n;

        startState = 0;
        for (int i = 0; i < 4; i++) {
            cin >> repeat;
            while (repeat--) {
                cin >> input;
                startState |= set(startState, input - 1, i);
            }
        }

        endState = result;
        for (int i = 0; i < 12 - n; i++) {
            endState = endState >> 2;
        }

        cout << bfs() << "\n";
    }
    return 0;
}