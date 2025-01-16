#include <algorithm>
#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

vector<vector<pair<int, int>>> rotations;
int blockSize;

// 90도 회전
vector<string> rotateBlock(const vector<string> &arr) {
    vector<string> ret(arr[0].size(), string(arr.size(), ' '));
    for (int i = 0; i < (int)arr.size(); i++) {
        for (int j = 0; j < (int)arr[0].size(); j++) {
            ret[j][arr.size() - i - 1] = arr[i][j];
        }
    }
    return ret;
}

// 블록 4회전 + 중복 제거
void generateRotations(vector<string> block) {
    rotations.clear();
    rotations.resize(0);
    for (int index = 0; index < 4; index++) {
        // (0,0)을 기준으로 상대좌표 생성
        vector<pair<int, int>> coords;
        int originY = -1, originX = -1;
        for (int i = 0; i < (int)block.size(); i++) {
            for (int j = 0; j < (int)block[i].size(); j++) {
                if (block[i][j] == '#') {
                    if (originY == -1) {
                        originY = i;
                        originX = j;
                    }
                    coords.push_back({i - originY, j - originX});
                }
            }
        }

        // 좌표 정렬해서 고유 모양화
        sort(coords.begin(), coords.end());
        rotations.push_back(coords);

        // 블록 90도 회전
        block = rotateBlock(block);
    }
    // 중복 제거
    sort(rotations.begin(), rotations.end());
    rotations.erase(unique(rotations.begin(), rotations.end()),
                    rotations.end());
    blockSize = (int)rotations[0].size();
}

// 보드
int boardH, boardW, R, C;
vector<string> board;
int covered[10][10]; // 0이면 비어있음, 1 이상이면 채워짐
int best;

bool setBlock(int y, int x, const vector<pair<int, int>> &shape, int delta) {
    bool canPlace = true;
    for (auto &cell : shape) {
        int ny = y + cell.first;
        int nx = x + cell.second;
        if (ny < 0 || ny >= boardH || nx < 0 || nx >= boardW) {
            canPlace = false;
        } else {
            if (delta == 1 && covered[ny][nx] != 0) {
                canPlace = false;
            }
        }
    }
    if (canPlace) {
        for (auto &cell : shape) {
            int ny = y + cell.first;
            int nx = x + cell.second;
            covered[ny][nx] += delta;
        }
    }
    return canPlace;
}

// emptyCells[index] 번째 칸을 검사
void backtrack(int index, int placed, int leftCells,
               const vector<pair<int, int>> &emptyCells) {
    // 가지치기
    if (placed + leftCells / blockSize <= best) return;

    // 모든 빈 칸을 확인 완료
    if (index == (int)emptyCells.size()) {
        best = max(best, placed);
        return;
    }

    int y = emptyCells[index].first;
    int x = emptyCells[index].second;

    // 이미 커버된 칸이면 넘어간다
    if (covered[y][x] != 0) {
        backtrack(index + 1, placed, leftCells, emptyCells);
        return;
    }

    // 블록 배치 시도
    for (auto &rot : rotations) {
        if (setBlock(y, x, rot, 1)) {
            backtrack(index + 1, placed + 1, leftCells - blockSize, emptyCells);
            setBlock(y, x, rot, -1);
        }
    }

    // 이 칸을 그냥 포기 (채우지 않음)
    covered[y][x] = 1;
    backtrack(index + 1, placed, leftCells - 1, emptyCells);
    covered[y][x] = 0;
}

int solveCase() {
    best = 0;
    vector<pair<int, int>> emptyCells;
    int leftCells = 0;

    // covered 배열 세팅 & 빈 칸 목록 만들기
    for (int i = 0; i < boardH; i++) {
        for (int j = 0; j < boardW; j++) {
            covered[i][j] = (board[i][j] == '#');
            if (covered[i][j] == 0) {
                emptyCells.push_back({i, j});
                leftCells++;
            }
        }
    }

    backtrack(0, 0, leftCells, emptyCells);
    return best;
}

int main() {
    fastIO;
    int repeat;
    cin >> repeat;
    while (repeat--) {
        cin >> boardH >> boardW >> R >> C;
        board.resize(boardH);
        for (int i = 0; i < boardH; i++) {
            cin >> board[i];
        }
        vector<string> block(R);
        for (int i = 0; i < R; i++) {
            cin >> block[i];
        }
        generateRotations(block);
        cout << solveCase() << "\n";
    }
    return 0;
}
