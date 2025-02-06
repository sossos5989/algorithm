#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

string cache, input;

int pi[1000000];
void failure() {
    int m = input.size();
    int begin = 1, i = 0;
    while (begin + i < m) {
        if (input[begin + i] == input[i]) {
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

void printPreSuf() {
    vector<int> result;
    int k = input.size();

    while (k) {
        result.push_back(k);
        k = pi[k - 1];
    }

    for (int i = result.size() - 1; i >= 0; --i) {
        cout << result[i] << " ";
    }
}

int main() {
    fastIO;
    cin >> input >> cache;
    input += cache;
    failure();
    printPreSuf();
    return 0;
}

// 어렵누..
// 입출력 개선,