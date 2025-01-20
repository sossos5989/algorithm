#include <iostream>
#include <vector>
using namespace std;

struct hint {
    int sum, usedMask, len;
};

int N, Q;
char board[20][20];
vector<hint> widthHint;
vector<hint> heightHint;
pair<int, int> hintIdx[20][20];
int mask[10][46][1 << 10]; // (len, sum, used mask)

int getSum(int mask) {
    int sum = 0;
    for (int i = 1; i < 10; ++i)
        if (mask & (1 << i)) sum += i;
    return sum;
}

void precalc() {
    for (int set = 2; set < 1024; set += 2)
        for (int usedMask = 0; usedMask < 1024; usedMask += 2) {
            if ((set | usedMask) != set) continue;
            int len = __builtin_popcount(set);
            int sum = getSum(set);
            mask[len][sum][usedMask] |= (set - usedMask);
        }
}

void print() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout << (int)board[i][j] << ' ';
        cout << '\n';
    }
}

int getMask(int y, int x) {
    hint &w = widthHint[hintIdx[y][x].first];
    hint &h = heightHint[hintIdx[y][x].second];
    return mask[w.len][w.sum][w.usedMask] & mask[h.len][h.sum][h.usedMask];
}

int getLen(int mask) { return __builtin_popcount(mask); }

void put(int y, int x, int num, bool type) {
    hint &w = widthHint[hintIdx[y][x].first];
    hint &h = heightHint[hintIdx[y][x].second];
    if (type) {
        board[y][x] = num;
        w.usedMask += (1 << num);
        h.usedMask += (1 << num);
    } else {
        board[y][x] = -1;
        w.usedMask -= (1 << num);
        h.usedMask -= (1 << num);
    }
}

bool search() {
    int y = -1, x = -1, minCands = 1023;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j] == -1) {
                int m = getMask(i, j);
                if (getLen(m) < getLen(minCands)) {
                    minCands = m;
                    y = i;
                    x = j;
                }
            }
        }
    }
    if (minCands == 0) return false;
    if (y == -1) {
        print();
        return true;
    }
    for (int num = 1; num <= 9; ++num)
        if (minCands & (1 << num)) {
            put(y, x, num, true);
            if (search()) return true;
            put(y, x, num, false);
        }
    return false;
}

void init() {
    widthHint.clear();
    heightHint.clear();
    int y, x, dir, sum;
    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
            board[i][j] = (board[i][j] == '0' ? 0 : -1);
        }
    cin >> Q;
    while (Q--) {
        cin >> y >> x >> dir >> sum;
        --y;
        --x;
        if (dir == 0) {
            widthHint.push_back({sum, 0, 0});
            int len = 0;
            while (board[y][++x] == -1) {
                hintIdx[y][x].first = widthHint.size() - 1;
                ++len;
            }
            widthHint.back().len = len;
        } else {
            heightHint.push_back({sum, 0, 0});
            int len = 0;
            while (board[++y][x] == -1) {
                hintIdx[y][x].second = heightHint.size() - 1;
                ++len;
            }
            heightHint.back().len = len;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precalc();

    int T;
    cin >> T;
    while (T--) {
        init();
        search();
    }
}