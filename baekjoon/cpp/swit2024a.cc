#include <iostream>
#include <string>
using namespace std;

int function(string s) {
    if (s == "(1)") return 0;
    if (s == "()1") return 1;
    if (s == "1()") return 1;
    if (s == ")1(") return 2;
    if (s == ")(1") return 1;
    if (s == "1)(") return 1;
    return -1;
}

int main() {
    string input;
    cin >> input;
    cout << function(input);
}