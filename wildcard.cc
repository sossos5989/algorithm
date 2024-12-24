#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string wildcard;
string list[50];
int cache[101][101];
string S, W;

bool match(int w, int s) {
    // 캐시 값 체크
    int& ret = cache[w][s];
    if(ret != -1) return ret;

    // 와일드카드와 문자가 일치하거나 '?' 처리
    if(w < W.size() && s < S.size() && (W[w] == '?' || W[w] == S[s])) 
        return ret = match(w+1, s+1);

    // 와일드카드 끝 처리
    if(w == W.size()) 
        return ret = (s == S.size());

    // '*' 처리
    if(W[w] == '*') {
        if(match(w+1, s) || (s < S.size() && match(w, s+1))) 
            return ret = 1;
    }

    return ret = 0;
}

int main() {
    int repeat;
    cin >> repeat;

    for(; repeat > 0; repeat--) {
        vector<string> answer;
        memset(cache, -1, sizeof(cache));
        cin >> W;

        int N;
        cin >> N;
        for(int i = 0; i < N; i++) {
            cin >> list[i];
        }

        for(int i = 0; i < N; i++) {
            S = list[i];
            memset(cache, -1, sizeof(cache));  // 각 문자열마다 캐시 초기화 했어야했음.
            if(match(0, 0)) answer.push_back(S);
        }

        sort(answer.begin(), answer.end());
        
        for(const auto& word : answer) {
            cout << word << "\n";
        }
    }

    return 0;
}
