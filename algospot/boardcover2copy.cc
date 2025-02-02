#include <algorithm>
#include <bitset>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int H, W, blockSize, best;
vector<vector<pair<int, int>>> rotations;
unordered_map<bitset<100>, int> cache;

void generateRotations(vector<vector<bool>> &block);
vector<vector<bool>> rotate(vector<vector<bool>> &arr);
int solve(vector<vector<bool>> &board);
void search(vector<vector<bool>> &board, int placed, int uncovered);
bitset<100> bijection(vector<vector<bool>> &board);
bool canSet(vector<vector<bool>> &board, int y, int x, int type);
void set(vector<vector<bool>> &board, int y, int x, int type, bool setBlock);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int R, C;
        cin >> H >> W >> R >> C;
        vector<vector<bool>> board(H, vector<bool>(W));
        for (int y = 0; y < H; ++y) {
            for (int x = 0; x < W; ++x) {
                char color;
                cin >> color;
                board[y][x] = color == '#';
            }
        }
        vector<vector<bool>> block(R, vector<bool>(C));
        for (int y = 0; y < R; ++y) {
            for (int x = 0; x < C; ++x) {
                char color;
                cin >> color;
                block[y][x] = color == '#';
            }
        }

        generateRotations(block);
        cout << solve(board) << '\n';
    }

    return 0;
}

void generateRotations(vector<vector<bool>> &block) {
    rotations.clear();
    rotations.resize(4);

    for (int rot = 0; rot < 4; ++rot) {
        int originY = -1, originX = -1;
        for (int i = 0; i < block.size(); ++i) {
            for (int j = 0; j < block[0].size(); ++j) {
                if (block[i][j]) {
                    if (originY == -1) {
                        originY = i;
                        originX = j;
                    }
                    rotations[rot].emplace_back(i - originY, j - originX);
                }
            }
        }
        if (rot < 3) {
            block = rotate(block);
        }
    }

    sort(rotations.begin(), rotations.end());
    rotations.erase(unique(rotations.begin(), rotations.end()),
                    rotations.end());

    blockSize = rotations[0].size();
}

vector<vector<bool>> rotate(vector<vector<bool>> &arr) {
    vector<vector<bool>> ret(arr[0].size(), vector<bool>(arr.size()));

    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr[0].size(); ++j) {
            ret[j][arr.size() - 1 - i] = arr[i][j];
        }
    }

    return ret;
}

int solve(vector<vector<bool>> &board) {
    best = 0;
    int uncovered = 0;

    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (!board[y][x]) {
                ++uncovered;
            }
        }
    }

    cache.clear();
    search(board, 0, uncovered);
    return best;
}

void search(vector<vector<bool>> &board, int placed, int uncovered) {
    if (placed + uncovered / blockSize <= best) {
        return;
    }

    bitset<100> covered = bijection(board);
    if (cache.find(covered) != cache.end() && placed <= cache[covered]) {
        return;
    }
    cache[covered] = placed;

    int y = -1, x = -1;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (!board[i][j]) {
                y = i;
                x = j;
                break;
            }
        }
        if (y != -1) {
            break;
        }
    }
    if (y == -1) {
        best = placed;
        return;
    }

    for (int type = 0; type < rotations.size(); ++type) {
        if (canSet(board, y, x, type)) {
            set(board, y, x, type, true);
            search(board, placed + 1, uncovered - blockSize);
            set(board, y, x, type, false);
        }
    }
    board[y][x] = true;
    search(board, placed, uncovered - 1);
    board[y][x] = false;
}

bitset<100> bijection(vector<vector<bool>> &board) {
    bitset<100> ret;
    int pos = 0;

    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (board[y][x]) {
                ret.set(pos);
            }
            ++pos;
        }
    }

    return ret;
}

bool canSet(vector<vector<bool>> &board, int y, int x, int type) {
    for (int i = 1; i < blockSize; ++i) {
        int ny = y + rotations[type][i].first;
        int nx = x + rotations[type][i].second;
        if (ny < 0 || ny >= H || nx < 0 || nx >= W || board[ny][nx]) {
            return false;
        }
    }
    return true;
}

void set(vector<vector<bool>> &board, int y, int x, int type, bool setBlock) {
    for (int i = 0; i < blockSize; ++i) {
        int ny = y + rotations[type][i].first;
        int nx = x + rotations[type][i].second;
        board[ny][nx] = setBlock;
    }
}