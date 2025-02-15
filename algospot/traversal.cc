#include <algorithm> // findIdx대신 std::find()이용
#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, preorder[100], inorder[100];

struct node {
    int value;
    node *left;
    z node *right;
    node(int value_, node *left_, node *right_)
        : value(value_), left(left_), right(right_) {}
};

int idx; // 전역변수 이용
node *makeTree(int x, int y) {
    node *ret;
    if (x > y || idx == n) return nullptr;
    int pivot = find(inorder + x, inorder + y, preorder[idx]) - inorder;
    ret = new node(preorder[idx++], makeTree(x, pivot - 1),
                   makeTree(pivot + 1, y));
    return ret;
}

void printTree(node *cand) {
    if (!cand) return;
    printTree(cand->left);
    printTree(cand->right);
    cout << cand->value << " ";
} // 후위 순회

int main() {
    fastIO;
    int C;
    cin >> C;
    while (C--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> preorder[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> inorder[i];
        }
        idx = 0;
        node *root = makeTree(0, n - 1);
        printTree(root);
        cout << "\n";
    }
    return 0;
} // 뭔가 쉽게 구현할 수 있을 것 같으나.. 쌩으로 전부 구현했음
