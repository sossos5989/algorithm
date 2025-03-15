#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

string cache;

int main() {
    fastIO;
    getline(cin, cache);
    string ret = "mixed";
    if (cache == "1 2 3 4 5 6 7 8") ret = "ascending";
    if (cache == "8 7 6 5 4 3 2 1") ret = "descending";
    cout << ret;
    return 0;
}