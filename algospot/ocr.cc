#define fastio cin.tie(0)->sync_with_stdio(0)
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

int words, sentence;
unordered_map<string, int> StringToInt;
unordered_map<int, string> IntToString;
double first[501], T[501][501], M[501][501];

int R;
int R_list[100];

int answer[100][502];

double DP[101][502];
double function(int steps, int prev) {
    if (steps == R) return 1.0;

    double &ret = DP[steps][prev];
    if (ret != -1.0) return ret;

    if (steps == 0) {
        ret = first[prev] * M[prev][ R_list[0] ] * function(1, prev);
        answer[0][prev] = prev;
    }
    else {
        ret = 0.0;
        for (int i = 0; i < words; i++) {
            double cand = T[prev][i] * M[i][R_list[steps]] * function(steps + 1, i);
            if (ret < cand) {
                ret = cand;
                answer[steps][prev] = i;
            }
        }
    }
    return ret;
}

// 교과서 내용 추가
string reconstruct(int segment, int previousMatch) {
    int choose = answer[segment][previousMatch];
    string ret = IntToString[choose];
    if (segment < R - 1) {
        ret += " " + reconstruct(segment + 1, choose);
    }
    return ret;
}

int main() {
    fastio;
    cin >> words >> sentence;
    for (int i = 0; i < words; i++) {
        string cache; cin >> cache;
        StringToInt[cache] = i;
        IntToString[i] = cache;
    }
    for (int i = 0; i < words; i++)
        cin >> first[i];
    for (int i = 0; i < words; i++)
        for (int j = 0; j < words; j++)
            cin >> T[i][j];
    for (int i = 0; i < words; i++)
        for (int j = 0; j < words; j++)
            cin >> M[i][j]; 

    while (sentence--) {
        fill(&DP[0][0], &DP[0][0] + 101 * 502, -1.0);

        // 문장 길이만큼 인식된 단어 입력
        cin >> R;
        for (int i = 0; i < R; i++) {
            string recognized;
            cin >> recognized;
            R_list[i] = StringToInt[recognized];
        }

        double maxProb = 0.0;
        int bestWord = 0;
        // "첫 단어를 i라고 가정" -> function(0, i) 호출
        for (int i = 0; i < words; i++) {
            double cand = function(0, i);
            if (cand > maxProb) {
                maxProb = cand;
                bestWord = i;
            }
        }

        cout << reconstruct(0, bestWord) << "\n";
    }
}