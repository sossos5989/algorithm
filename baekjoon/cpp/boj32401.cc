#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int prev = 0, isN = 0, count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            if (prev && isN == 1) count++;
            prev = 1;
            isN = 0;
        } else if (s[i] == 'N')
            isN++;
    }
    cout << count;
    return 0;
}