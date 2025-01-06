#include <cstring>
#include <iostream>
#include <math.h>
#include <stdexcept>
#include <vector>

class SquareMatrix {
  private:
    int size;
    std::vector<std::vector<double>> data;

  public:
    // Constructor to initialize a size x size matrix with all elements set to
    // 0.0
    SquareMatrix(int size_)
        : size(size_), data(size_, std::vector<double>(size_, 0.0)) {}

    // Static method to create an identity matrix of given size
    static SquareMatrix identity(int size_) {
        SquareMatrix I(size_);
        for (int i = 0; i < size_; ++i) {
            I.data[i][i] = 1.0;
        }
        return I;
    }

    // Overloaded operator[] to access rows of the matrix
    std::vector<double> &operator[](int row) {
        if (row < 0 || row >= size) {
            throw std::out_of_range("Row index out of bounds");
        }
        return data[row];
    }

    // Const version of the overloaded operator[] for read-only access
    const std::vector<double> &operator[](int row) const {
        if (row < 0 || row >= size) {
            throw std::out_of_range("Row index out of bounds");
        }
        return data[row];
    }

    // Overloaded multiplication operator for matrix multiplication
    SquareMatrix operator*(const SquareMatrix &other) const {
        if (size != other.size) {
            throw std::invalid_argument(
                "Matrix sizes do not match for multiplication");
        }

        SquareMatrix result(size);

        for (int i = 0; i < size; ++i) {
            for (int k = 0; k < size; ++k) {
                if (data[i][k] != 0.0) { // Optimization for sparse matrices
                    for (int j = 0; j < size; ++j) {
                        result.data[i][j] += data[i][k] * other.data[k][j];
                    }
                }
            }
        }

        return result;
    }

    // Method to raise the matrix to the power of exponent using binary
    // exponentiation
    SquareMatrix pow(int exponent) const {
        if (exponent < 0) {
            throw std::invalid_argument("Exponent must be non-negative");
        }

        SquareMatrix result = SquareMatrix::identity(size);
        SquareMatrix base = *this;

        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = result * base;
            }
            base = base * base;
            exponent /= 2;
        }

        return result;
    }

    // (Optional) Method to display the matrix for debugging purposes
    void print() const {
        for (const auto &row : data) {
            for (double val : row) {
                printf("%8.2f ", val);
            }
            printf("\n");
        }
    }
};
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

// 시작은 0번 곡부터..
// k분 30초..
// 다행인건. 노래는 1분 2분 3분 4분이 끝이라는 것
//
int n, k, m;
int length[50];
double next_song[50][50];
int like[10];

double DP[1000001][51];
double function(int minute, int prev, int favSong) {
    if (minute < 0) return (prev == favSong) ? 1.0 : 0.0;

    double &ret = DP[minute][prev];
    if (ret > -1.0) return ret;

    ret = 0;
    for (int i = 0; i < n; i++) {
        ret += next_song[prev][i] * function(minute - length[i], i, favSong);
    }
    return ret;
}

vector<double> function2() {
    double DP[5][50];
    memset(DP, 0, sizeof(DP));
    DP[0][0] = 1.0;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            double &prob = DP[i % 5][j];
            prob = 0;
            for (int last = 0; last < n; last++) {
                prob +=
                    DP[((i - length[last]) + 5) % 5][last] * next_song[last][j];
            }
        }
    }
    vector<double> ret(n);
    for (int song = 0; song < n; song++) {
        for (int i = k - length[song] + 1; i <= k; i++) {
            ret[song] += DP[i % 5][song];
        }
    }
    return ret;
}

vector<double> function3() {
    SquareMatrix W(4 * n);
    for (int i = 0; i < 3 * n; i++) {
        W[i][i + n] = 1.0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            W[3 * n + i][(4 - length[j]) * n + j] = next_song[j][i];
        }
    }
    SquareMatrix Wk = W.pow(k);
    vector<double> ret(n);
    for (int song = 0; song < n; song++) {
        for (int start = 0; start < length[song]; start++) {
            ret[song] += Wk[(3 - start) * n + song][3 * n];
        }
    }
    return ret;
}

int main() {
    fastIO;
    int repeat;
    cin >> repeat;
    cout.precision(15);
    while (repeat--) {
        cin >> n >> k >> m;
        for (int i = 0; i < n; i++) {
            cin >> length[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> next_song[i][j];
            }
        }
        for (int i = 0; i < m; i++) {
            cin >> like[i];
        }
        // vector<double> cache = function2();
        vector<double> cache = function3();
        for (int i = 0; i < m; i++) {
            // fill(&DP[0][0], &DP[0][0] + 1000001 * 51, -999.0);
            cout << cache[like[i]] << " ";
        }
        cout << endl;
    }
    return 0;
}