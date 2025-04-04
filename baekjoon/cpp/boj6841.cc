#include <iostream>
#include <unordered_map>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

unordered_map<string, string> m;

int main() {
    fastIO;
    m["CU"] = "see you";
    m[":-)"] = "I’m happy";
    m[":-("] = "I’m unhappy";
    m[";-)"] = "wink";
    m[":-P"] = "stick out my tongue";
    m["(~.~)"] = "sleepy";
    m["TA"] = "totally awesome";
    m["CCC"] = "Canadian Computing Competition";
    m["CUZ"] = "because";
    m["TY"] = "thank-you";
    m["YW"] = "you’re welcome";
    m["TTYL"] = "talk to you later";
    string s;
    cin >> s;
    cout << m[s];
    return 0;
}