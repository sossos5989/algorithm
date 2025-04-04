#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

const int MOD = 1000000007;
const vector<vector<long long>> A = {{1, 1}, {1, 0}};

vector<vector<long long>> product(vector<vector<long long>> a,
                                  vector<vector<long long>> b) {
    vector<vector<long long>> ret = {{0, 0}, {0, 0}};

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++) {
                ret[i][j] += a[k][j] * b[i][k];
                ret[i][j] %= MOD;
            }

    return ret;
}

vector<vector<long long>> rec(long long k) {
    if (k == 1) return A;
    vector<vector<long long>> ret = rec(k / 2);
    ret = product(ret, ret);
    if (k % 2) ret = product(ret, A);
    return ret;
}

int main() {
    fastIO;
    long long n, sum = 0;
    cin >> n;
    if (n > 2) {
        vector<vector<long long>> matrix = rec(n - 2);
        for (int i = 0; i < 2; i++) {
            sum += matrix[0][i];
            sum %= MOD;
        }
    } else
        sum = 1;

    cout << sum;
    return 0;
}