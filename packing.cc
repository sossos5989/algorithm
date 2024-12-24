#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#define fastio cin.tie(0)->sync_with_stdio(0)

#define MAX(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

int cache[100][1001];  // [0]은 부피, [1]은 절박도
int N;  // N개 항목
int M;  // M 용량
int volume[100];  // 부피
int need[100];  // 절박도
string name[100];

int function(int index, int capacity) {
    if (index == N) return 0;  // 기저 사례
    int& ret = cache[index][capacity];
    if(ret != -1) return ret;  // 메모이제이션

    ret = function(index + 1, capacity);

    if(capacity >= volume[index]) ret = MAX(ret, function(index + 1, capacity - volume[index]) + need[index]);
    
    return ret;
}

void reconstruct(int index, int capacity, vector<string>& picked) {
    if (index == N) return;  // 기저사례
    if (function(index, capacity) == function(index + 1, capacity)) {
        reconstruct(index + 1, capacity, picked);
    } else {
        picked.push_back(name[index]);
        reconstruct(index + 1, capacity - volume[index], picked);
    }
}

int main() {
    fastio;
    int repeat;
    cin >> repeat;
    for (int i = 0; i < repeat; i++)  // 테스트 케이스
    {
        memset(cache, -1, sizeof(cache));  // cache의 모든 원소 -1 초기화
        cin >> N >> M;  // 입력
        for (int j = 0; j < N; j++) {cin >> name[j] >> volume[j] >> need[j];}
        vector<string> list;
        reconstruct(0, M, list);
        cout << function(0, M) << " " << list.size() << endl;  // 출력
        for (const auto& element : list) {
            cout << element << endl;
        }
    }

    return 0;
}