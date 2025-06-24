#include <iostream>
using namespace std;

int main() {
    double p, r;
    cin >> p >> r;
    double cache = p / r;
    string ans;
    if (cache < 0.2)
        ans = "weak";
    else if (cache < 0.4)
        ans = "normal";
    else if (cache < 0.6)
        ans = "strong";
    else
        ans = "very strong";
    cout << ans;
    return 0;
}