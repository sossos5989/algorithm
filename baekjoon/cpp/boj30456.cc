#include <iostream>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    cout << string(l - 1, '1') << n;
    return 0;
}