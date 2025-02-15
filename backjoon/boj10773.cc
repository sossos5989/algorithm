#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, input, psum[100000], ptr;
int main() {
    fastIO;
    cin >> n;
    while (n--) {
        cin >> input;
        if (input == 0) {
            ptr--;
        } else if (ptr) {
            psum[ptr] = psum[ptr - 1] + input;
            ptr++;
        } else {
            psum[ptr] = input;
            ptr++;
        }
    }
    cout << psum[ptr - 1];
    return 0;
} // base case를 따로 처리하면 if문 하나 줄일 수 있음