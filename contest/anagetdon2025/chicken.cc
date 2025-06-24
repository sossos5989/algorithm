#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    string a, b, c;
    cin >> a >> b >> c;

    if (a == "Rock" && b == "Scissors" && c == "Scissors")
        cout << "Eunyoung";
    else if (a == "Scissors" && b == "Rock" && c == "Scissors")
        cout << "Jinha";
    else if (a == "Scissors" && b == "Scissors" && c == "Rock")
        cout << "Minjung";
    else if (a == "Scissors" && b == "Paper" && c == "Paper")
        cout << "Eunyoung";
    else if (a == "Paper" && b == "Scissors" && c == "Paper")
        cout << "Jinha";
    else if (a == "Paper" && b == "Paper" && c == "Scissors")
        cout << "Minjung";
    else if (a == "Paper" && b == "Rock" && c == "Rock")
        cout << "Eunyoung";
    else if (a == "Rock" && b == "Paper" && c == "Rock")
        cout << "Jinha";
    else if (a == "Rock" && b == "Rock" && c == "Paper")
        cout << "Minjung";
    else
        cout << "Youngwoo";
    return 0;
}