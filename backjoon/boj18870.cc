#include <algorithm>
#include <iostream>
#include <unordered_map>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, cache, original[1000000], input[1000000];
int main() {
    fastIO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cache;
        original[i] = input[i] = cache;
    }
    sort(input, input + n);
    unordered_map<int, int> mapping;
    mapping[input[0]] = 0;
    for (int i = 1, count = 0; i < n; i++) {
        if (input[i] != input[i - 1]) {
            count++;
        }
        mapping[input[i]] = count;
    }
    for (int i = 0; i < n; i++) {
        cout << mapping[original[i]] << " ";
    }
    return 0;
}
// pair<int, int>를 잘 사용한다면, unordered_map을 사용하지 않을 수도 있다.
// 정확히는 unordered_map처럼 쓸 수 있다.