#include <cstring>
#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

// 교과서랑 다르게 풀어보려했는데 못풀겠음

// turn이 한 줄을 만들었는지를 파악함.
bool isFinished(const vector<string> &board, char turn) {
    for (int y = 0; y < 3; y++) {
        if (board[y][0] == turn && board[y][1] == turn && board[y][2] == turn) {
            return true;
        }
    }

    for (int x = 0; x < 3; x++) {
        if (board[0][x] == turn && board[1][x] == turn && board[2][x] == turn) {
            return true;
        }
    }

    if (board[0][0] == turn && board[1][1] == turn && board[2][2] == turn) {
        return true;
    }

    if (board[0][2] == turn && board[1][1] == turn && board[2][0] == turn) {
        return true;
    }

    return false;
}

int bijection(const vector<string> &board) {
    int ret = 0;
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            ret *= 3;
            if (board[y][x] == 'o')
                ret += 1;
            else if (board[y][x] == 'x')
                ret += 2;
        }
    }
    return ret;
}

char determineNextTurn(const vector<string> &board) {
    int xCount = 0, oCount = 0;

    for (const string &row : board) {
        for (char cell : row) {
            if (cell == 'x')
                xCount++;
            else if (cell == 'o')
                oCount++;
        }
    }

    // 조건에 따라 반환
    if (xCount == oCount) return 'x';
    if (xCount == oCount + 1) return 'o';
    return '?';
}

int DP[19683];
int canWin(vector<string> &board, char turn) {
    if (isFinished(board, (char)('o' + 'x' - turn))) return -1;
    int &ret = DP[bijection(board)];
    if (ret != -2) return ret;
    int minValue = 2;
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            if (board[y][x] == '.') {
                board[y][x] = turn;
                minValue =
                    min(minValue, canWin(board, (char)('o' + 'x' - turn)));
                board[y][x] = '.';
            }
        }
    }
    if (minValue == 2 || minValue == 0) return ret = 0;
    return ret = -minValue;
}

int main() {
    fastIO;
    int repeat;
    cin >> repeat;
    for (int i = 0; i < 19683; i++) {
        DP[i] = -2;
    }
    while (repeat--) {
        vector<string> input(3);
        for (int i = 0; i < 3; i++) {
            cin >> input[i];
        }
        string ans;
        int WinLose = canWin(input, determineNextTurn(input));
        if (WinLose == 0) {
            ans = "TIE";
        } else if (determineNextTurn(input) == 'x') {
            ans = WinLose == 1 ? "x" : "o";
        } else if (determineNextTurn(input) == 'o') {
            ans = WinLose == 1 ? "o" : "x";
        }
        cout << ans << endl;
    }
    return 0;
}