#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int half_n = N/2;
    for (int i = 0; i < N/2; i++) {cout << half_n + i + 1 << " " << half_n - i << " ";}
    if(N % 2 == 1) cout << N;
    return 0;
}

