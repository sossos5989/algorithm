#include <iostream>
#include <math.h>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n;
vector<double> list;

// 함수와 입력 값이 주어졌을 때, 출력하는 함수
double function(const vector<double> &f, double input) {
    double ret = 0.0;
    for (int i = 0; i < f.size(); i++) {
        ret += f[i] * pow(input, i);
    }
    return ret;
}

// 미분했을 때, 차수를 제공하는 함수
vector<double> differentiation(const vector<double> &input) {
    vector<double> ret;
    for (int i = 1; i < input.size(); i++) {
        ret.push_back(input[i] * i);
    }
    return ret;
}

// 이차방정식을 해결하는 함수
vector<double> naive(const vector<double> &input) {
    vector<double> ret;
    double rand = 0;
    double gap = sqrt(input[1] * input[1] - 4 * input[2] * input[0]);
    rand = -input[1];
    ret.push_back((rand - gap) / (2 * input[2]));
    ret.push_back((rand + gap) / (2 * input[2]));
    return ret;
}

// n차 방정식의 해를 구하는 함수
vector<double> solve(const vector<double> &input) {
    int degree = input.size() - 1;
    // base case
    if (degree == 2) return naive(input);

    // 도함수의 해들, 양 옆에 -20 20을 추가
    vector<double> critical_points = solve(differentiation(input));

    // 극점들
    vector<double> points;
    points.push_back(-21.0);
    for (int i = 0; i < degree - 1; i++) {
        points.push_back(critical_points[i]);
    }
    points.push_back(21.0);

    vector<double> ret;

    // 극점들 간의 있는 해를 이분탐색으로 찾음. (문제에서는 있다고 가정)
    for (int i = 0; i < points.size() - 1; i++) {
        double xlo = points[i], xhi = points[i + 1];
        double ylo = function(input, xlo), yhi = function(input, xhi);

        if (ylo * yhi > 0) continue;
        if (ylo > yhi) {
            swap(ylo, yhi);
            swap(xlo, xhi);
        }

        int it = 100;
        while (it--) {
            double mid = (xlo + xhi) / 2.0;
            double midf = function(input, mid);
            if (ylo * function(input, mid) > 0) {
                xlo = mid;
                ylo = midf;
            } else {
                xhi = mid;
                yhi = midf;
            }
        }
        ret.push_back(xlo);
    }
    return ret;
}

int main() {
    fastIO;
    int T;
    cin >> T;
    cout.precision(20);
    while (T--) {
        cin >> n;
        list.clear();
        list.resize(n + 1);
        for (int i = n; i >= 0; i--) {
            cin >> list[i];
        }

        vector<double> answer = solve(list);

        for (int i = 0; i < n; i++) {
            cout << answer[i] << " ";
        }
        cout << endl;
    }
    return 0;
}