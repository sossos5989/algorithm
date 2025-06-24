#include <iostream>
using namespace std;

int main() {
    int d, m, month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string weekday[7] = {"Wednesday", "Thursday", "Friday", "Saturday",
                         "Sunday",    "Monday",   "Tuesday"};
    cin >> d >> m;
    for (int i = 0; i <= m - 2; i++)
        d += month[i];
    cout << weekday[d % 7];
    return 0;
}