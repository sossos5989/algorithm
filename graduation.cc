#include <cstring>
#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

// 전공 과목 n개 중 k개 이상을 들어야 한다.
// m학기와 한 학기에 최대로 들을 수 있는 과목 l개가 주어진다.
// 각 과목에는 선수 과목이 존재(없을수도 있음), 선수 과목을 먼저 이수해야 한다.
// 각 학기에는 개설되는 과목이 주어진다.
// k개 이상을 듣기 위해 들어야하는 최소한의 학기 수를 구하시오,
// 불가능하면, 불가능함을 구하시오.
int n, k, m, l;

// 선수과목을 bitmask로 표현한다. 선수과목이면 1
int subject[12];

// 각 학기당 들을 수 있는 과목을 비트 자리에 1로 표현한다.(bitmask)
int semester[10];

int DP[1 << 12][10];
int graduation(int mask, int sem) {
    // base case
    if (__builtin_popcount(mask) >= k) return 0;
    if (sem >= m) return 999; // 못찾음

    // recursive case
    int &ret = DP[mask][sem];
    if (ret != -1) return ret;

    ret = 999;

    // 이번 학기에 들을 수 있는 과목 중 듣지 않은 과목 중
    // 선수과목을 듣지 않은 것을 제외
    int available = semester[sem] & ~mask;
    for (int i = 0; i < n; i++) {
        if (((available >> i) & 1) && (mask & subject[i]) != subject[i]) {
            available &= ~(1 << i);
        }
    }

    if (__builtin_popcount(available) <= l) {
        ret = min(ret, 1 + graduation(mask | available, sem + 1));
    } else {
        for (int subset = available; subset;
             subset = ((subset - 1) & available)) {
            if (__builtin_popcount(subset) == l) { // 최대 l개 선택
                ret = min(ret, 1 + graduation(mask | subset, sem + 1));
            }
        }
    }
    ret = min(ret, graduation(mask, sem + 1)); // 휴학

    return ret;
}

void init() {
    memset(subject, 0, sizeof(subject));
    memset(semester, 0, sizeof(semester));
    memset(DP, -1, sizeof(DP));
    cin >> n >> k >> m >> l;
    int size, cache;
    for (int i = 0; i < n; i++) {
        cin >> size;
        while (size--) {
            cin >> cache;
            subject[i] |= (1 << cache);
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> size;
        while (size--) {
            cin >> cache;
            semester[i] |= (1 << cache);
        }
    }
}

void print() {
    int answer = graduation(0, 0);
    if (answer > 50)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << answer << endl;
}

int main() {
    fastIO;
    int T;
    cin >> T;
    while (T--) {
        init();
        print();
    }
    return 0;
}