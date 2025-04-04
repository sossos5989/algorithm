#include <algorithm>
#include <iostream>
#include <vector>

#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastIO;
    int n, input;
    vector<int> list;
    cin >> n;
    while (n--) {
        cin >> input;
        auto it = lower_bound(list.begin(), list.end(), input);
        if (it == list.end())
            list.push_back(input);
        else
            *it = input;
    }
    cout << list.size();
    return 0;
}