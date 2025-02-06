#include <cstring>
#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, ret, sizeN;
string cache, H, needle; // H는 haystack, S는 Needle

int pi[200000];
void failure() {
    int begin = 1, i = 0;
    while (begin + i < sizeN) {
        if (needle[begin + i] == needle[i]) {
            i++;
            pi[begin + i - 1] = i;
        } else {
            if (i == 0) {
                begin++;
            } else {
                begin += i - pi[i - 1];
                i = pi[i - 1];
            }
        }
    }
}

void findKMP() {
    int begin = 1, i = 0;
    while (begin < sizeN) {
        if (i < sizeN && H[(begin + i) % sizeN] == needle[i]) {
            i++;
            if (i == sizeN) {
                ret = begin;
                return;
            }
        } else {
            if (i == 0) {
                begin++;
            } else {
                begin += i - pi[i - 1];
                i = pi[i - 1];
            }
        }
    }
}

int main() {
    fastIO;
    int C;
    cin >> C;
    while (C--) {
        cin >> n >> needle;
        sizeN = needle.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> cache;
            if (i % 2 == 0) {
                H = move(cache);
            } else {
                needle = move(cache);
            }
            failure();
            findKMP();
            sum += ret;
        }
        cout << sum << "\n";
    }
    return 0;
}