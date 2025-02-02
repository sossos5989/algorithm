#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

string input;
int cache[10010];
const int INF = 1000007;
template <typename T>
T Min(T a, T b, T c) {
    if (a < b && a < c)
        return a;
    else if (b < c)
        return b;
    else
        return c;
}

int test(string s) {
    vector<int> numlist(s.size());
    for (int i = 0; i < s.size(); i++) {numlist[i] = s[i] - '0';}
    if(s.size() < 3) return INF;
    
    int diff = numlist[1] - numlist[0];
    bool IsMonotonic = true;
    for (int i = 0; i < s.size() - 1; i++) {if(diff != numlist[i+1] - numlist[i]) IsMonotonic = false;}
    if (IsMonotonic && diff == 0) return 1;
    if (IsMonotonic && (diff == 1 || diff == -1)) return 2;
    if (IsMonotonic) return 5;

    bool IsVibrate = true;
    for (int i = 0; i < s.size() - 2; i++) {
        if(numlist[i+2] != numlist[i]) IsVibrate = false;
    }
    if (IsVibrate) return 4;
    
    return 10;
}

int pi(int index) {
    int& ret = cache[index];
    if(ret != -1) return ret;
    if(index > input.size()) return ret = INF;
    if(index == input.size()) return ret = 0;
    int test1 = test(input.substr(index, 3));
    int test2 = test(input.substr(index, 4));
    int test3 = test(input.substr(index, 5));
    return ret = Min<int>(test1 + pi(index + 3), test2 + pi(index + 4), test3 + pi(index + 5));
}

int main() {
    int repeat;
    cin >> repeat;
    while (repeat > 0)
    {
        memset(cache,-1,sizeof(cache));
        cin >> input;
        cout << pi(0) << "\n";
        repeat--;
    }
    return 0;
}