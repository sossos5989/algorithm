#include <cmath>
#include <iostream>

using namespace std;

double A, B, C;
double decision(double x) { return A * x + B * sin(x) - C; }

int main() {
    cin >> A >> B >> C;

    double lo = 0.0, hi = (C + B) / A;
    for (int iter = 0; iter < 100; iter++) {
        double mid = (lo + hi) / 2.0;
        if (decision(mid) < 0)
            lo = mid;
        else
            hi = mid;
    }
    cout.precision(6);
    cout << fixed << (lo + hi) / 2.0;
    return 0;
}
