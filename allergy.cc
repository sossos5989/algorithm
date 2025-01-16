#include <algorithm>
#include <bitset>
#include <iostream>
#include <unordered_map>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

// 친구들 수 n, 음식 수 m, 구하려는 수 best
int n, m, best;

// friend의 이름을 0 1 2 3 ...n-1로 대응시킵니다.
unordered_map<string, int> StrToInt;
// 음식->친구
vector<vector<int>> foodToFriendsList;
// 친구->음식
vector<vector<int>> friendToFoodsList;
// 첫 번째 원소는 먹을 수 있는 음식의 개수,
// 두 번째 원소는 친구의 번호(0~n-1)
vector<pair<int, int>> FoodSizeSortedList;

// TestCase마다 수행되는 작업. 초기화 수행
void init() {
    StrToInt.clear();
    foodToFriendsList.clear();
    friendToFoodsList.clear();
    FoodSizeSortedList.clear();
    best = 50;
}

// 데이터를 전처리합니다.
void initData() {
    friendToFoodsList.resize(n);
    // friendToFoodsList
    for (int food = 0; food < foodToFriendsList.size(); ++food) {
        for (int friendID : foodToFriendsList[food]) {
            friendToFoodsList[friendID].push_back(food);
        }
    }
    // FoodSizeSortedList
    for (int friendID = 0; friendID < friendToFoodsList.size(); ++friendID) {
        FoodSizeSortedList.push_back(
            {friendToFoodsList[friendID].size(), friendID});
    }
    sort(FoodSizeSortedList.begin(), FoodSizeSortedList.end());
}

// 위 정렬한 vector의 pair 두번째 값을 바탕으로 friends의 음식 선정
// 첫번째 골라보고, 두번째 골라보고... 만약 골라져있으면 pass이런느낌
void backtrack(long long fr, int index, int count) {
    // 기초적인 가지치기
    if (best <= count) return;

    // base case 모든 사람이 먹을 수 있는 음식 존재
    if (fr == ((1LL << n) - 1)) {
        best = min(count, best);
        return;
    }

    // 종료조건은 필요함.
    if (index == n) return;

    // recursive case
    int friendID = FoodSizeSortedList[index].second;

    // 채워져있는건 pass합니다.
    if (fr & (1LL << friendID)) backtrack(fr, index + 1, count);

    // 현재 FoodSizeSortedList[index]에 있는
    // friendID의 food들 중 무엇을 고를지 정합니다.
    for (int &food : friendToFoodsList[friendID]) {
        long long oldFr = fr;

        // 이후 이 food를 먹을 수 있는 friend의 비트마스크를 1로 채웁니다.
        for (int &friends : foodToFriendsList[food]) {
            fr |= (1LL << friends);
        }
        backtrack(fr, index + 1, count + 1);

        // 이후 이 food를 먹을 수 있는 friend의 비트마스크를 되돌립니다.
        fr = oldFr;
    }
}

int solve() {
    // 친구(0, n-1)이 먹을 수 있는 음식이 존재 시 1, 아니면 0
    long long FoodExist = 0;
    backtrack(FoodExist, 0, 0);
    return best;
}

int main() {
    fastIO;
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        init();
        vector<string> friends(n);
        for (int i = 0; i < n; i++) {
            string cache;
            cin >> cache;
            StrToInt[cache] = i;
        }
        for (int i = 0; i < m; i++) {
            int size;
            cin >> size;
            vector<int> list;
            for (int j = 0; j < size; j++) {
                string cache;
                cin >> cache;
                list.push_back(StrToInt[cache]);
            }
            foodToFriendsList.push_back(list);
        }
        initData();
        solve();
        cout << best << endl;
    }
    return 0;
}
