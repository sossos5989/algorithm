#include <iostream>
#include <math.h>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int list1[100001], list2[100001];
int target1[100001], target2[100001];

int main() {
    fastIO;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> list1[i];

    for (int i = 0; i < n; i++)
        cin >> list2[i];

    for (int i = 0; i < n; i++)
        cin >> target1[i];

    for (int i = 0; i < n; i++)
        cin >> target2[i];

    for (int i = 0; i < n - 1; i++) {
        int gap = target1[i] - list1[i];
        list1[i] += gap;
        list1[i + 1] += gap;
    }

    for (int i = 0; i < n - 1; i++) {
        int gap = target2[i] - list2[i];
        list2[i] += gap;
        list2[i + 1] += gap;
    }

    if (n == 2) {
        cout << (abs((list1[n - 1] - list2[n - 1]) -
                     (target1[n - 1] - target2[n - 1])) == 0
                     ? "YES"
                     : "NO");
    } else {
        cout << (abs((list1[n - 1] - list2[n - 1]) -
                     (target1[n - 1] - target2[n - 1])) <= 1
                     ? "YES"
                     : "NO");
    }
}