#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

double ret;
string grade;

int main() {
    fastIO;
    cin >> grade;
    if (grade == "A+")
        ret = 4.3;
    else if (grade == "A0")
        ret = 4.0;
    else if (grade == "A-")
        ret = 3.7;
    else if (grade == "B+")
        ret = 3.3;
    else if (grade == "B0")
        ret = 3.0;
    else if (grade == "B-")
        ret = 2.7;
    else if (grade == "C+")
        ret = 2.3;
    else if (grade == "C0")
        ret = 2.0;
    else if (grade == "C-")
        ret = 1.7;
    else if (grade == "D+")
        ret = 1.3;
    else if (grade == "D0")
        ret = 1.0;
    else if (grade == "D-")
        ret = 0.7;
    else
        ret = 0.0;
    cout.precision(1);
    cout << fixed << ret;
}