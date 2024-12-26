#define fastio cin.tie(0)->sync_with_stdio(0)
#include <bits/stdc++.h>
using namespace std;

int words, sentence;
unordered_map<string, int> StringToInt;
unordered_map<int, string> IntToString;

// B[i]: 단어 i가 문장의 첫 단어로 등장할 확률
double firstProb[501];
// T[i][j]: 실제 단어가 i일 때 다음 단어로 j가 등장할 확률
double nextProb[501][501];
// M[i][j]: 실제 단어 i가 분류기에 의해 j로 인식될 확률
double recogProb[501][501];

int main() {
    fastio;
    cin >> words >> sentence;

    // 단어 목록 입력
    for(int i = 0; i < words; i++){
        string w;
        cin >> w;
        StringToInt[w] = i;
        IntToString[i] = w;
    }

    // 첫 단어 확률
    for(int i = 0; i < words; i++){
        cin >> firstProb[i];
    }

    // 전이 확률(다음 단어로 넘어갈 때)
    for(int i = 0; i < words; i++){
        for(int j = 0; j < words; j++){
            cin >> nextProb[i][j];
        }
    }

    // 인식 확률
    // recogProb[i][j] = "실제 단어 i를 j로 인식할 확률"
    for(int i = 0; i < words; i++){
        for(int j = 0; j < words; j++){
            cin >> recogProb[i][j];
        }
    }

    // 문장(테스트 케이스) 처리
    while(sentence--) {
        int n; // 문장(인식된 단어)의 개수
        cin >> n;

        vector<int> recognized(n);
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            recognized[i] = StringToInt[s];
        }

        // DP[step][i]: step번째(0-based) 실제 단어를 i라고 했을 때의 최대 확률
        static double DP[101][501];
        // choice[step][i]: step번째 단어가 i일 때, 이전 단계에서 선택한 단어
        static int choice[101][501];

        // (1) DP 초기화: step = 0
        for(int i = 0; i < words; i++){
            // 첫 단어가 i일 확률 * 인식 확률(M[i][recognized[0]])
            DP[0][i] = firstProb[i] * recogProb[i][ recognized[0] ];
            choice[0][i] = -1; // 이전 단어가 없음
        }

        // (2) DP 채우기: step = 1..(n-1)
        for(int step = 1; step < n; step++){
            for(int i = 0; i < words; i++){
                double bestVal = 0.0;
                int bestPrev = 0;
                // 이전 단계의 실제 단어 후보 j
                for(int j = 0; j < words; j++){
                    double cand = DP[step-1][j] * nextProb[j][i];
                    if(cand > bestVal){
                        bestVal = cand;
                        bestPrev = j;
                    }
                }
                // 실제 단어 i일 때, 이번 조각이 recognized[step]라고 인식될 확률 곱
                DP[step][i] = bestVal * recogProb[i][ recognized[step] ];
                choice[step][i] = bestPrev;
            }
        }

        // (3) 마지막 단어로 최적 확률을 갖는 i 찾기
        double maxVal = 0.0;
        int bestLast = 0;
        for(int i = 0; i < words; i++){
            if(DP[n-1][i] > maxVal){
                maxVal = DP[n-1][i];
                bestLast = i;
            }
        }

        // (4) 역추적으로 실제 단어 시퀀스 복원
        vector<int> path(n);
        int cur = bestLast;
        for(int step = n - 1; step >= 0; step--){
            path[step] = cur;
            cur = choice[step][cur];
        }

        // (5) 복원된 문장 출력
        //     - path[0]부터 path[n-1]까지가 순서대로 실제 단어
        for(int i = 0; i < n; i++){
            cout << IntToString[path[i]] << ( (i+1 == n) ? '\n' : ' ' );
        }
    }

    return 0;
}
