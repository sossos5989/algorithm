#include <iostream>
#include <vector>
#include <algorithm>  // for lower_bound

using namespace std;

int lis(const vector<int>& sequence) {
    vector<int> lis;  // LIS를 유지할 배열
    
    for (int x : sequence) {
        // lis 배열에서 x보다 크거나 같은 첫 번째 원소의 위치를 찾음
        auto it = lower_bound(lis.begin(), lis.end(), x);
        
        if (it == lis.end()) {
            lis.push_back(x);  // x가 lis의 모든 원소보다 크면 뒤에 추가
        } else {
            *it = x;  // 그렇지 않으면 해당 위치의 원소를 x로 교체
        }
    }
    
    return lis.size();  // lis 배열의 크기가 LIS의 길이
}

int main() {
    int repeat;
    cin >> repeat;
    
    for (; repeat > 0; repeat--) {
        int N;
        cin >> N;
        
        vector<int> list(N);
        for (int i = 0; i < N; i++) {
            cin >> list[i];
        }
        
        cout << lis(list) << "\n";
    }

    return 0;
}