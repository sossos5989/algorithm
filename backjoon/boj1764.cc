#include <algorithm>
#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m;
vector<string> list1, list2, answer;

int main() {
    fastIO;
    cin >> n >> m;
    list1.resize(n);
    list2.resize(m);
    for (int i = 0; i < n; i++) {
        cin >> list1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> list2[i];
    }
    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (list1[i] == list2[j]) {
            answer.push_back(list1[i]);
            i++;
            j++;
        } else if (list1[i] > list2[j]) {
            if (j == m) break;
            j++;
        } else if (list1[i] < list2[j]) {
            if (i == n) break;
            i++;
        }
    }
    cout << answer.size() << "\n";
    for (string &i : answer) {
        cout << i << "\n";
    }
    return 0;
}

// Trie를 써도 되고, 굳이 list를 두개 해서 만들지 않고,
// binary_search를 이용해서 풀 수도 있다.