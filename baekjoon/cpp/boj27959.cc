#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    cout << (100 * n >= m ? "Yes" : "No");
    return 0;
}