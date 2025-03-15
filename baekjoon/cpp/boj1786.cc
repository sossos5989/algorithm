#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

string haystack, needle;

int pi[1000000];
void failure() {
    int m = needle.size();
    int begin = 1, i = 0; // two pointer
    while (begin + i < m) {
        if (needle[begin + i] == needle[i]) {
            ++i;
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
} // O(m)

vector<int> result;

void searchKMP() {
    int n = haystack.size(), m = needle.size();
    int begin = 0, i = 0; // two pointer
    while (begin <= n - m) {
        if (i < m && haystack[begin + i] == needle[i]) {
            ++i;
            if (i == m) result.push_back(begin + 1);
        } else {
            if (i == 0) {
                begin++;
            } else {
                begin += i - pi[i - 1];
                i = pi[i - 1];
            }
        }
    }
} // O(n)

int main() {
    fastIO;
    getline(cin, haystack);
    getline(cin, needle);

    failure();
    searchKMP();

    cout << result.size() << "\n";
    for (int &i : result) {
        cout << i << " ";
    }
    return 0;
}