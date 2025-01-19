#include <algorithm>
#include <bitset>
#include <cstring>
#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, q;

// 유의할 점: board의 좌표는 1부터 시작
bool input_board[21][21];

// 답
int board[21][21];

// 경우의 수를 구하기 위한 factorial의 값을 미리 구해놓습니다.
int factorial[10];
void initFactorial() {
    factorial[0] = 1;
    factorial[1] = 1;
    for (int i = 2; i < 10; i++) {
        factorial[i] = factorial[i - 1] * i;
    }
}

vector<vector<int>> countList[10][46];

// 카쿠로의 조건 절의 선택할 수 있는 숫자의 조합을
// vector<int> 형태로 모두 구합니다.
void initCase() {
    // 0부터 2^9-1까지의 숫자를 탐색합니다.
    for (int i = 0; i < (1 << 9); i++) {
        vector<int> combination;
        int len = 0;
        int sum = 0;
        // 각 자리수를 계산하며 데이터를 전처리합니다.
        for (int j = 0; j < 9; j++) {
            if ((i >> j) & 1) {
                combination.push_back(j + 1);
                len++;
                sum += (j + 1);
            }
        }
        countList[len][sum].push_back(combination);
    }
}

struct condition {
    int y;
    int x;
    int dir;
    int sum;
    int len = 0;
    int count = 0;
    vector<pair<int, int>> cells;

    void setCells() {
        cells.clear();
        if (dir == 0) { // 가로
            for (int c = x + 1; c <= n && input_board[y][c]; c++) {
                cells.push_back({y, c});
            }
        } else { // 세로
            for (int r = y + 1; r <= n && input_board[r][x]; r++) {
                cells.push_back({r, x});
            }
        }
        len = (int)cells.size();
    }

    void calCount() { count = countList[len][sum].size() * factorial[len]; }
};

vector<condition> conditions; // 조건 Q개

bool solveKakuro(int idx) {
    // 모든 조건을 처리했다면 => 해답 완성
    if (idx == (int)conditions.size()) return true;

    condition &cond = conditions[idx];

    vector<vector<int>> &combList = countList[cond.len][cond.sum];

    for (vector<int> &comb : combList) {
        vector<int> arr = comb;
        do {
            // 현재 순열에서 값이 충돌하면,
            bool conflict = false;
            for (int i = 0; i < cond.len; i++) {
                int r = cond.cells[i].first;
                int c = cond.cells[i].second;
                int val = arr[i];

                if (board[r][c] != 0 && board[r][c] != val) {
                    conflict = true;
                    break;
                }
            }
            if (conflict) continue;

            // 시도
            vector<int> backup(cond.len);
            for (int i = 0; i < cond.len; i++) {
                int r = cond.cells[i].first;
                int c = cond.cells[i].second;
                backup[i] = board[r][c];
                board[r][c] = arr[i];
            }

            // recursive case;
            if (solveKakuro(idx + 1)) {
                return true;
            }

            // 복원
            for (int i = 0; i < cond.len; i++) {
                int r = cond.cells[i].first;
                int c = cond.cells[i].second;
                board[r][c] = backup[i];
            }

        } while (next_permutation(arr.begin(), arr.end()));
    }

    return false; // 모든 조합+순열해도 안되면 false
}

int main() {
    fastIO;
    int T;
    cin >> T;
    initFactorial();
    initCase();
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> input_board[i][j];
            }
        }
        cin >> q;
        conditions.clear();
        conditions.resize(q);
        for (int i = 0; i < q; i++) {
            cin >> conditions[i].y >> conditions[i].x >> conditions[i].dir >>
                conditions[i].sum;
            conditions[i].setCells();
            conditions[i].calCount();
        }

        sort(conditions.begin(), conditions.end(),
             [](const condition &a, const condition &b) {
                 return a.count < b.count;
             });

        solveKakuro(0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
