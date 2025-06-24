#include <iostream>
using namespace std;

int main() {
    int n, flag = 0;
    string str;
    cin >> n >> str;
    for (int i = 0; i <= n - 4; i++)
        if (str.substr(i, 4) == "gori") flag = 1;
    cout << (flag ? "YES" : "NO");
    return 0;
}