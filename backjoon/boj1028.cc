#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int R, C;

int main() {
    fastIO;
    cin >> R >> C;
    vector<string> list(C);
    for (int i = 0; i < R; i++) {
        cin >> list[i];
    }

    return 0;
}

// 어떤 점(x,y)이 있다고 치자.
// abs(x'+y') = k를 만족하면 k단계임
// 5개면 3단계.. 2단계.//.. 찾으면 종료
// 미완
