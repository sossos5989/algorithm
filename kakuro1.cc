#include <bits/stdc++.h>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

static const int MAXN = 21;

int n, color[MAXN][MAXN], value[MAXN][MAXN], hint[MAXN][MAXN][2];
int q, sum[MAXN * MAXN], length[MAXN * MAXN], known[MAXN * MAXN];
int candidates[10][46][1024];

// 조건의 길이, 합, 사용된 숫자가 주어지면, 사용 가능한 숫자들을
// bitmask 형태로 제공하는 candidates[len][sum][known]을
// 계산하는 함수
void generateCandidates() {
    for (int set = 2; set < (1 << 10); set += 2) {
        int setSize = __builtin_popcount(set);
        int setSum = 0;
        for (int i = 1; i <= 9; i++) {
            if (set & (1 << i)) setSum += i;
        }
        for (int usedMask = 0; usedMask < (1 << 10); usedMask += 2) {
            if ((set | usedMask) != set) continue;
            candidates[setSize][setSum][usedMask] |= (set & ~usedMask);
        }
    }
}

// put
void put(int y, int x, int val) {
    for (int h = 0; h < 2; h++) {
        known[hint[y][x][h]] += (1 << val);
    }
    value[y][x] = val;
}

// remove
void remove(int y, int x, int val) {
    for (int h = 0; h < 2; h++) {
        known[hint[y][x][h]] -= (1 << val);
    }
    value[y][x] = 0;
}

// 힌트 번호가 주어지면, 후보의 bitmask를 반환
int getCandHint(int h) { return candidates[length[h]][sum[h]][known[h]]; }

// 좌표가 주어지면, 후보의 bitmask를 반환
int getCandCoord(int y, int x) {
    return getCandHint(hint[y][x][0]) & getCandHint(hint[y][x][1]);
}

int getSize(int mask) {
    int count = 0;
    while (mask) {
        count += (mask & 1);
        mask >>= 1;
    }
    return count;
}

bool search() {
    int y = -1, x = -1, minCands = 1023;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // 빈 칸에 대해
            if (color[i][j] == 1 && value[i][j] == 0) {
                int cands = getCandCoord(i, j);
                if (cands == 0) {
                    return false; // 가능한 숫자가 없음
                }
                if (getSize(cands) < getSize(minCands)) {
                    minCands = cands;
                    y = i;
                    x = j;
                }
            }
        }
    }

    // base case, 출력 이후 종료
    if (y == -1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << value[i][j] << " ";
            }
            cout << "\n";
        }
        return true;
    }

    // recursive case
    for (int num = 1; num <= 9; num++) {
        if (minCands & (1 << num)) {
            put(y, x, num);
            if (search()) return true;
            remove(y, x, num);
        }
    }
    return false;
}

int main() {
    fastIO;
    generateCandidates();
    int T;
    cin >> T;
    while (T--) {
        memset(color, 0, sizeof(color));
        memset(value, 0, sizeof(value));
        memset(hint, 0, sizeof(hint));
        memset(sum, 0, sizeof(int) * q);
        memset(length, 0, sizeof(int) * q);
        memset(known, 0, sizeof(int) * q);

        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> color[i][j];
            }
        }

        cin >> q;
        for (int hintIndex = 0; hintIndex < q; hintIndex++) {
            int Y, X, Dir, S;
            cin >> Y >> X >> Dir >> S;

            sum[hintIndex] = S;
            known[hintIndex] = 0;
            length[hintIndex] = 0;

            if (Dir == 0) {
                int col = X + 1;
                while (col <= n && color[Y][col] == 1) {
                    hint[Y][col][0] = hintIndex;
                    length[hintIndex]++;
                    col++;
                }
            } else {
                int row = Y + 1;
                while (row <= n && color[row][X] == 1) {
                    hint[row][X][1] = hintIndex;
                    length[hintIndex]++;
                    row++;
                }
            }
        }

        search();
    }
    return 0;
}
