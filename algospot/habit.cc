#include <algorithm>
#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int k;
string input;

struct Comparator {
    const vector<int> &group;
    int t;
    Comparator(const vector<int> &_group, int _t) : group(_group), t(_t) {}
    bool operator()(int a, int b) {
        if (group[a] != group[b]) return group[a] < group[b];
        return group[a + t] < group[b + t];
    }
};

vector<int> getSuffixArray() {
    int n = input.size(), t = 1;
    vector<int> group(n + 1); // perm[]을 정렬하기 위한 기준(그룹)
    for (int i = 0; i < n; i++) {
        group[i] = input[i];
    }
    group[n] = -1;
    vector<int> perm(n); // 접두사의 index들
    for (int i = 0; i < n; i++) {
        perm[i] = i;
    }
    while (t < n) {
        Comparator compareUsing2T(group, t);
        sort(perm.begin(), perm.end(), compareUsing2T);
        t *= 2;
        if (t >= n) break;
        vector<int> newGroup(n + 1);
        newGroup[n] = -1;
        newGroup[perm[0]] = 0;
        for (int i = 0; i < n; i++) {
            if (compareUsing2T(perm[i - 1], perm[i])) {
                newGroup[perm[i]] = newGroup[perm[i - 1]] + 1;
            } else {
                newGroup[perm[i]] = newGroup[perm[i - 1]];
            }
        }
        group = newGroup;
    }
    return perm;
}

int commonPrefix(int i, int j) {
    int ret = 0;
    for (; i < input.size() && j < input.size() && input[i] == input[j];
         i++, j++, ret++) {
    }
    return ret;
}

int longestFrequent() {
    vector<int> a = getSuffixArray();
    int ret = 0;
    for (int i = 0; i + k <= input.size(); i++) {
        ret = max(ret, commonPrefix(a[i], a[i + k - 1]));
    }
    return ret;
}

int main() {
    fastIO;
    int C;
    cin >> C;
    while (C--) {
        cin >> k >> input;
        cout << longestFrequent() << "\n";
    }
    return 0;
}