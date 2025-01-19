#include <bits/stdc++.h>
using namespace std;

// 최대 20x20으로 가정 (문제에서 21까지 가능이라면 알맞게 늘려 사용)
static const int MAXN = 21;

// input_board[r][c] = true 이면 흰 칸(숫자를 놓는 셀), false 이면 검은 칸
bool input_board[MAXN][MAXN];
int boardVal[MAXN][MAXN]; // 실제로 (r,c)에 할당된 값 (0이면 미할당)
int domainMask[MAXN]
              [MAXN]; // (r,c)가 가질 수 있는 후보를 비트마스크로 표현(1~9)

/*
  - 예: domainMask[r][c] = 0b0100110010 이면
    2진수로 ( ‭100110010‬ ) => 1~9 중 켜져 있는 비트가 후보
  값이 됨. (가령 2,5,7번 비트가 켜져 있으면, 값 2/5/7 이 가능)
  - bit i(1-based)가 켜져 있으면 "i가 후보"라는 뜻
*/

// 조건(합) 구조체
struct Condition {
    int sum;                      // 원하는 합
    vector<pair<int, int>> cells; // 이 조건에 속한 셀 좌표들
};

// 전체 조건(예: Q개)
vector<Condition> conditions;
// (r, c)가 속한 condition 인덱스 목록
vector<int> cellConstraints[MAXN][MAXN];

// 편의를 위해, 1~9 숫자를 비트로 바꾸고 / 다시 되돌리는 헬퍼 함수
inline int valToBit(int v) { return (1 << v); }
inline bool canBeUsed(int mask, int v) {
    // mask에 v의 비트가 켜져 있는지 확인
    return (mask & (1 << v)) != 0;
}

// (r,c)에 value를 할당해도 되는지(조건 위배 없는지) 검사
bool checkConsistency(int r, int c, int value) {
    // 해당 셀이 속한 모든 condition을 확인
    for (int condIdx : cellConstraints[r][c]) {
        Condition &cond = conditions[condIdx];
        // 같은 condition 내에 이미 할당된 값들과 겹치면 안 됨 (카쿠로는 중복
        // 불가)
        int partialSum = 0;
        int assignedCount = 0;
        for (auto &rc : cond.cells) {
            int rr = rc.first;
            int cc = rc.second;
            int assignedVal = boardVal[rr][cc];
            if ((rr == r && cc == c)) {
                // 아직 boardVal[r][c]에 할당 전이지만 value라는 후보를 쓴다고
                // 가정
                assignedVal = value;
            }
            if (assignedVal != 0) {
                partialSum += assignedVal;
                assignedCount++;
            }
        }
        // 부분합이 조건 sum을 넘어가면 불가능
        if (partialSum > cond.sum) return false;

        // 이미 할당된 값과 지금 넣으려는 value가 중복이면 불가능
        // => 예: cond에 속한 어떤 셀이 assignedVal=5 인데 지금 value도 5면 X
        //    (단, 0이면 아직 미할당이므로 무시)
        for (auto &rc : cond.cells) {
            int rr = rc.first;
            int cc = rc.second;
            if (rr == r && cc == c) continue; // 자기 자신
            if (boardVal[rr][cc] == value && value != 0) {
                // 같은 condition 내 중복
                return false;
            }
        }

        // 만약 해당 condition의 셀이 전부 할당되었다면, sum이 정확히 맞아야 함
        if (assignedCount == (int)cond.cells.size()) {
            if (partialSum != cond.sum) {
                return false;
            }
        }
    }
    return true;
}

// (r,c)에 value를 할당해보고, 문제 없으면 true, 아니면 false
bool assignValue(int r, int c, int value) {
    // 먼저 checkConsistency로 조건 위배 여부 확인
    if (!checkConsistency(r, c, value)) return false;
    // 위배되지 않는다면, 실제로 할당
    boardVal[r][c] = value;
    // domainMask도 "value만 가능"한 상태로 설정(임시)
    domainMask[r][c] = valToBit(value);
    return true;
}

// (r,c)에 할당했던 value를 되돌리기(0으로)
void unassignValue(int r, int c, int oldMask) {
    boardVal[r][c] = 0;
    // domainMask 복원
    domainMask[r][c] = oldMask;
}

// 아직 값이 정해지지 않은 셀 중, domainMask의 켜져 있는 비트 개수가 가장
// 작은(MRV) 셀을 찾는다. 만약 모두 할당이 끝났다면 (-1, -1)을 리턴
pair<int, int> pickNextCell(int n) {
    int minSize = 9999999;
    pair<int, int> best = make_pair(-1, -1);
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
            if (!input_board[r][c]) continue;  // 검은 칸
            if (boardVal[r][c] != 0) continue; // 이미 할당된 셀은 패스
            // domainMask[r][c] 내에 켜진 비트 수를 센다
            int m = domainMask[r][c];
            if (m == 0) {
                // 도메인 자체가 없으면 => 이 경로는 이미 불가능이므로
                // pickNextCell에서 바로 반환(백트래킹)
                return make_pair(r, c);
            }
            int bitCount = __builtin_popcount(m);
            if (bitCount < minSize) {
                minSize = bitCount;
                best = make_pair(r, c);
            }
        }
    }
    return best;
}

// 백트래킹
bool solveKakuro(int n) {
    // MRV로 다음 할당할 셀을 찾기
    pair<int, int> cell = pickNextCell(n);
    int r = cell.first, c = cell.second;

    // 만약 (r, c)가 (-1, -1)이라면 => 모든 셀이 할당된 상태 (해결 완료)
    if (r == -1 && c == -1) {
        return true;
    }
    // 만약 domainMask가 0인 셀을 골랐다면 => 할당 불가 => 실패
    if (domainMask[r][c] == 0) {
        return false;
    }

    // domainMask[r][c]에 켜져 있는 후보들을 순회
    int possibleMask = domainMask[r][c];
    // 백트래킹을 쉽게 하기 위해, 현재 domainMask를 백업
    int oldMask = domainMask[r][c];

    // 1~9까지 각각 확인하면서, 비트가 켜져 있는 value만 시도
    for (int value = 1; value <= 9; value++) {
        if (!canBeUsed(possibleMask, value)) continue; // 이 값은 후보가 아님

        // (r,c)에 value를 실제로 할당 시도
        if (assignValue(r, c, value)) {
            // 다음 단계 재귀
            if (solveKakuro(n)) return true;
            // 실패 시 원상복구
            unassignValue(r, c, oldMask);
        }
    }

    // 모든 후보를 시도했으나 성공 못 했다면 return false
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; // 테스트 케이스 개수
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        // 보드 입력
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> input_board[i][j];
                // boardVal 초기화
                boardVal[i][j] = 0;
            }
        }

        // 도메인 초기화
        // 흰 칸: 1~9 가능 => bitmask = (1<<1)|(1<<2)|...|(1<<9) = (1<<10)-2 =
        // 1022 검은 칸: 0
        const int FULL_MASK =
            (1 << 10) -
            2; // 1~9 비트가 1인 값(0b1111111110가 아니라 1-based라 1<<v)
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (input_board[i][j]) {
                    domainMask[i][j] = FULL_MASK;
                } else {
                    domainMask[i][j] = 0;
                }
            }
        }

        // 조건(합) 입력
        int q;
        cin >> q;
        conditions.clear();
        conditions.resize(q);

        // cellConstraints도 초기화
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cellConstraints[i][j].clear();
            }
        }

        // 각 조건 입력
        // dir=0이면 가로, 1이면 세로(예: 질문 코드와 동일 가정)
        for (int i = 0; i < q; i++) {
            int y, x, dir, s;
            cin >> y >> x >> dir >> s;
            conditions[i].sum = s;
            // 조건에 속하는 칸 cells 파악
            vector<pair<int, int>> cellsInCond;
            if (dir == 0) {
                // 가로
                // x+1부터 흰 칸이 끝날 때까지
                for (int c = x + 1; c <= n && input_board[y][c]; c++) {
                    cellsInCond.push_back({y, c});
                }
            } else {
                // 세로
                for (int r = y + 1; r <= n && input_board[r][x]; r++) {
                    cellsInCond.push_back({r, x});
                }
            }
            conditions[i].cells = cellsInCond;

            // cellConstraints에 등록
            for (auto &rc : cellsInCond) {
                cellConstraints[rc.first][rc.second].push_back(i);
            }
        }

        // 이제 백트래킹
        bool ok = solveKakuro(n);

        // 결과 출력
        // ok가 true라면 boardVal에 완성된 값들이 들어 있음
        // (문제 형식에 맞추어 출력)
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // 흰 칸이면 보드에 할당된 값, 검은 칸이면 0 출력(등등 규칙은
                // 상황 따라 조정)
                if (!input_board[i][j])
                    cout << 0 << " ";
                else
                    cout << boardVal[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
