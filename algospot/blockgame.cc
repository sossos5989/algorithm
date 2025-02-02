#include <bits/stdc++.h>
using namespace std;

#define fastIO cin.tie(0)->sync_with_stdio(0)

inline int cell(int y, int x) { return 1 << (y * 5 + x); }

vector<int> moves;

void precalc() {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            vector<int> cells;
            for (int dy = 0; dy < 2; dy++) {
                for (int dx = 0; dx < 2; dx++) {
                    cells.push_back(cell(y + dy, x + dx));
                }
            }
            int square = cells[0] + cells[1] + cells[2] + cells[3];
            for (int i = 0; i < 4; i++) {
                int Lblock = square - cells[i];
                moves.push_back(Lblock);
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            // 가로 2칸
            moves.push_back(cell(i, j) + cell(i, j + 1));
            // 세로 2칸
            moves.push_back(cell(j, i) + cell(j + 1, i));
        }
    }
}

char cache[1 << 25];
char play(int board) {
    // 메모이제이션
    char &ret = cache[board];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = 0; i < (int)moves.size(); i++) {
        int blockMask = moves[i];
        if ((board & blockMask) == 0) {
            int newBoard = board | blockMask;
            if (play(newBoard) == 0) {
                ret = 1;
                break;
            }
        }
    }
    return ret;
}

int main() {
    fastIO;
    int C;
    cin >> C;

    precalc();

    while (C--) {
        int board = 0;
        for (int i = 0; i < 5; i++) {
            string line;
            cin >> line;
            for (int j = 0; j < 5; j++) {
                if (line[j] == '#') {
                    board |= cell(i, j);
                }
            }
        }

        memset(cache, -1, sizeof(cache));

        if (play(board) == 1) {
            cout << "WINNING\n";
        } else {
            cout << "LOSING\n";
        }
    }

    return 0;
}
