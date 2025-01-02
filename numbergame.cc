#include <cstring>
#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

// 이게 왜 난이도 하 문제인데...
// 플레이어가 할 수 있는 선택
// 플레이어 1부터 시작. 플레이어가 할 수 있는 선택은 다음과 같다
// 1. 왼쪽 선택
// 2. 오른쪽 선택
// 3. 왼쪽 둘 제거
// 4. 오른쪽 둘 제거

// bool을 줘서 매번 3, 4번을 선택할 수 있는지 여부를 준다.
// 뭐 그다음엔 +-로 주면 되겟지.. 이것도 아까 틱택토 문제처럼 서로 - +가
// 번갈아가면서 구현해도 좋을 듯하다. 더블 포인터를 써서 구현 ?

int n;
int list[50];

// function은 a <= k <= b 인 k index를 다룬다고 가정한다.
int DP[50][50][2];
int function(int a, int b, int HWturn) {
    if (a > b) return 0;
    if (a == b && HWturn) return list[a];
    if (a == b && !HWturn) return -list[a];

    int &ret = DP[a][b][HWturn];
    if (ret != -1) return ret;
    ret = 0;
    if (HWturn) {
        ret = max(function(a + 1, b, !HWturn) + list[a],
                  function(a, b - 1, !HWturn) + list[b]);
        if (b - a >= 2) {
            int cache =
                max(function(a + 2, b, !HWturn), function(a, b - 2, !HWturn));
            ret = max(ret, cache);
        }
    } else {
        ret = min(function(a + 1, b, !HWturn) - list[a],
                  function(a, b - 1, !HWturn) - list[b]);
        if (b - a >= 2) {
            int cache =
                min(function(a + 2, b, !HWturn), function(a, b - 2, !HWturn));
            ret = min(ret, cache);
        }
    }
    return ret;
}

int main() {
    fastIO;
    int repeat;
    cin >> repeat;
    while (repeat--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> list[i];
        }
        memset(DP, -1, sizeof(DP));
        cout << function(0, n - 1, 1) << endl;
    }
    return 0;
}