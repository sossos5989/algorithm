#include <algorithm>
#include <iostream>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int idx = 0, input, arr[100001];
void dfs(int start, int end) {
    // cout << start << ' ' << end << '\n';
    if (start > end - 1) return;
    if (start == end - 1) {
        cout << arr[start] << '\n';
        return;
    }

    int mid = end;
    for (int i = start + 1; i < end; i++)
        if (arr[start] < arr[i]) {
            mid = i;
            break;
        }

    dfs(start + 1, mid);
    dfs(mid, end);

    cout << arr[start] << '\n';
}

int main() {
    fastIO;
    while (cin >> input)
        arr[idx++] = input;
    dfs(0, idx);
    return 0;
}