#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int k;
vector<string> input(15);

void removeSubstrings() {
    sort(input.begin(), input.end(),
         [&](const string &a, const string &b) -> bool {
             return a.size() > b.size();
         });

    vector<string> result;

    for (int i = 0; i < input.size(); ++i) {
        bool isSub = false;
        for (int j = 0; j < result.size(); ++j) {
            if (result[j].find(input[i]) != string::npos) {
                isSub = true;
                break;
            }
        }
        if (!isSub) {
            result.push_back(input[i]);
        }
    }
    input = std::move(result); // result도 초기화됩니다.
    k = input.size();

} // 포함 관계에 있는 원소를 없앱니다.

int overlap[15][15];
void calOverlap() {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            overlap[i][j] = 0;
            for (int L = min(input[i].size(), input[j].size()); L >= 1; --L) {
                if (input[i].substr(input[i].size() - L, L) ==
                    input[j].substr(0, L)) {
                    overlap[i][j] = L;
                    break;
                }
            }
        }
    }
} // overlap[][]을 미리 구합니다.

int DP[15][1 << 15];
int restore(int last, int used) {
    if (used == (1 << k) - 1) return 0; // base case

    int &ret = DP[last][used];
    if (ret != -1) return ret; // 메모이제이션

    ret = 0;
    for (int i = 0; i < k; i++) {
        if (used & (1 << i)) continue;
        int cand = overlap[last][i] + restore(i, used | (1 << i));
        ret = max(ret, cand);
    }
    return ret; // recursive case
}

string traceback(int last, int used) {
    if (used == (1 << k) - 1) return "";

    for (int i = 0; i < k; i++) {
        if (used & (1 << i)) continue;
        int ifUsed = restore(i, used + (1 << i)) + overlap[last][i];
        if (restore(last, used) == ifUsed)
            return (input[i].substr(overlap[last][i]) +
                    traceback(i, used | (1 << i)));
    }
    return "???";
}

int main() {
    fastIO;
    int repeat;
    cin >> repeat;
    while (repeat--) {
        cin >> k;
        input.clear();
        input.resize(k);
        for (int i = 0; i < k; i++) {
            cin >> input[i];
        }

        memset(DP, -1, sizeof(DP));
        removeSubstrings();
        calOverlap();

        int bestOverlap = -1;
        int bestIndex = 0;
        for (int i = 0; i < k; i++) {
            int val = restore(i, 1 << i);
            if (val > bestOverlap) {
                bestOverlap = val;
                bestIndex = i;
            }
        }

        string finalString =
            input[bestIndex] + traceback(bestIndex, 1 << bestIndex);

        cout << finalString << "\n";
    }
    return 0;
}
