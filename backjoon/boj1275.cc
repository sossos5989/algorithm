#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, q, list[100001], sum[100001];

struct turn {
    int x;
    int y;
    int a;
    int b;
};

vector<turn> turn_list(100001);

int answer[100001];

int main() {
    fastIO;
    // 입력 처리
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> list[i];
    }
    for (int i = 1; i <= q; i++) {
        cin >> turn_list[i].x >> turn_list[i].y >> turn_list[i].a >>
            turn_list[i].b;
        if (turn_list[i].x > turn_list[i].y)
            swap(turn_list[i].x, turn_list[i].y);
    }

    // 1부터 i까지의 합을 계산하는 sum()
    sum[1] = list[1];
    for (int i = 2; i <= n; i++) {
        sum[i] += sum[i - 1] + list[i];
    }

    // sum()을 이용해서 미리 answer[0...q-1]를 구함
    for (int i = 1; i <= q; i++) {
        answer[i] = sum[turn_list[i].y] - sum[turn_list[i].x - 1];
    }

    // turn의 입력에 따라 answer를 수정한다. O(n^2) 아마 안될듯?
    for (int i = 1; i <= q; i++) {
        cout << answer[i] << endl;
        for (int j = i + 1; j <= q; j++) {
            if (turn_list[j].y >= turn_list[i].a &&
                turn_list[j].x <= turn_list[i].a) {
                answer[j] += turn_list[i].b - list[turn_list[i].a];
            }
        }
    }

    return 0;
}