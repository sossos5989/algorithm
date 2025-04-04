#include <iostream>
#include <unordered_map>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    double ans = 0, b = 0;
    string a, c;
    unordered_map<string, double> grade2double = {
        {"A+", 4.5}, {"A0", 4.0}, {"B+", 3.5}, {"B0", 3.0}, {"C+", 2.5},
        {"C0", 2.0}, {"D+", 1.5}, {"D0", 1.0}, {"F", 0.0},  {"P", 0.0}};

    double course = 0;
    for (int i = 0; i < 20; i++) {
        cin >> a >> b >> c;
        if (c != "P") course += b;
        ans += grade2double[c] * b;
    }
    cout << fixed << ans / course;
    return 0;
}