#include <iostream>
#include <string>

using namespace std;

const __float128 PI =
    3.1415926535897932384626433832795028841971693993751058209749445923Q;

__float128 A, B, C, factorial[50];

__float128 powq(__float128 x, long long num) {
    if (num <= 0) return 1.0Q;
    return (__float128)x * powq(x, num - 1);
}

__float128 sinq(__float128 x, int step = 20) {
    if (step <= 0) return x;
    return (powq(-1, step) * powq(x, 2 * step + 1) / factorial[2 * step + 1]) +
           sinq(x, step - 1);
}

bool decision(__float128 x) {
    return A * x +
               B * sinq(x - (__float128)(long long)(x / (2 * PI)) * (2 * PI)) -
               C <
           0.0Q;
}

void print(__float128 value) {
    __float128 multiplier = 1000000.0Q;
    __float128 product = value * multiplier + 0.5Q;
    string ans = to_string((long long)product);
    if (ans.size() <= 6) {
        string blank(6 - ans.size(), '0');
        cout << "0." << blank << ans;
    } else
        cout << ans.substr(0, ans.size() - 6) << '.'
             << ans.substr(ans.size() - 6, 6);
}

int main() {
    factorial[0] = 1.0Q;
    for (int i = 1; i < 50; i++)
        factorial[i] = factorial[i - 1] * (__float128)i;

    long double tmpA, tmpB, tmpC;
    cin >> tmpA >> tmpB >> tmpC;
    A = tmpA;
    B = tmpB;
    C = tmpC;

    __float128 lo = (C - B) / A - 0.1Q;
    __float128 hi = (C + B) / A + 0.1Q;

    for (int iter = 0; iter < 100; iter++) {
        __float128 mid = (lo + hi) / 2.0Q;
        if (decision(mid))
            lo = mid;
        else
            hi = mid;
    }

    print((lo + hi) / 2.0Q);

    return 0;
}
