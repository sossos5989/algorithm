#include <iostream>
#include <string>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

// 문제 이해부터 힘들었는데 연속으로 3번 같은 단어가 아니면 됨

// 사실 생각해보니까 개수 세는 게 아니라서,

int k, n, a;

// 단어길이 1 * (k-1), 2 * (k-1) ... 이것을 n이하까지
int main() {
    fastIO;
    cin >> k >> n >> a;
    string ret = "";
    if (a == 1) {
        if (n < k) {
            for (int i = 0; i < n; i++) {
                ret += 'A';
            }
        } else {
            ret += "-1";
        }
    } else if (k == 2) {
        if (n > a) {
            ret += "-1";
        } else {
            for (int i = 0; i < n; i++) {
                ret += 'A' + i;
            }
        }
    } else {
        string cache = "";
        for (int i = 0; i < k - 1; i++) {
            cache += 'A';
        }
        cache += 'B';
        for (int i = 0; i < k - 1; i++) {
            ret += cache;
        }
    }

    cout << ret << endl;
    return 0;
}

// AAB AAB ABA ABA ABB / AAB AAB ABA ABA ABB AAB / AAB AAB ABA ABA BBA