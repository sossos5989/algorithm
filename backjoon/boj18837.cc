#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, k;
int list[100001];
vector<int> length(100000); // list[i,n)의 최대 LIS길이
vector<int> index[100001];  // length의 특정 값이 나타나는 index를 정리
vector<int> lis;
vector<int> seg(100000 * 4);

int main() {
    fastIO;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    for (int i = 0; i < n; i++) {
        int &cand = list[i];
        auto it = lower_bound(lis.begin(), lis.end(), cand);
        if (it == lis.end()) {
            lis.push_back(cand);
            length[i] = lis.size();
            index[lis.size()].push_back(i);
        } else {
            *it = cand;
            length[i] = it - lis.begin() + 1;
            index[it - lis.begin() + 1].push_back(i);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << length[i] << " ";
    }

    // 이제 여기서 지랄맞은 부분 스타트

    // 우리가 구하려고 하는 것은 결국
    // ways[i]: i index에서 시작하는 lis의 개수를 구해야하는데
    // 솔직히 naive방식인 그래프 + dfs방식은 구현이 쉬움 그나마
    // 근데 우리는 시간 복잡도를 줄여야 하기 때문에
    // 세그트리를 써야함

    // 1. 특정 구간(a,b)에서 어떤 value를 세는 query가 O(1)
    // 에 동작해야 함.
    // 따라서 countSegTree를 init(), 및 query까지 만들어야함

    // 2. 이제 이 countSegTree를 바탕으로, 이진탐색을 곁들여서
    // ways[i]를 구함. 이때 순방향 역방향이든 상관없음
    // 그럼 시간 복잡도는? O(log n * log n * n)

    // 3. 이 ways[i]를 바탕으로,

    // for (int i = 1; i <= lis.size(); i++) {
    //     index[i]; // 에 대해 역방향으로 탐색
    // }

    // 20250308 아직 내수준으론 못푼다고 결론을 내림
    return 0;
}
