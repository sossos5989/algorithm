#define fastio cin.tie(0)->sync_with_stdio(0)
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

// 개선할거, dp를 vector로, edge도 vector로 한다
int N, D, P;
int end_ptr;
int list[51][51];
double cache[50][100];

double count(int start, int days) {
    if(days == D) return (start == end_ptr) ? 1.0 : 0.0;
    
    double& ret = cache[start][days];
    if (!std::isnan(ret)) return ret;
    double sum1 = 0;
    double sum2 = 0;
    for (int i = 0; i < N; i++) {
        int& cache = list[start][i];
        if (cache == 1) {
            sum1 += count(i, days + 1);
            sum2 += cache;
        }
    }
    return ret = sum1 / sum2;
}

int main() {
    fastio;
    int repeat; cin >> repeat;
    while (repeat-- > 0) {
        cin >> N >> D >> P;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> list[i][j];
            }
        }
        
        int T;
        cin >> T;
        while (T--) {
            fill(&cache[0][0], &cache[0][0]+ 50 * 100, NAN);
            cin >> end_ptr;
            cout.precision(8);
            cout << count(P, 0) << " ";
        }
        cout << "\n";
    } 
    return 0;
}