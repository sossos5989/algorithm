#include <algorithm> // findIdx대신 std::find()이용
#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, idx, inorder[100000], postorder[100000];

struct node {
    int value;
    node *left;
    node *right;
    node(int value_, node *left_, node *right_)
        : value(value_), left(left_), right(right_) {}
};

node *makeTree(int x, int y) {
    node *root;
    if (x > y || idx == n) return nullptr;
    int pivot = find(inorder + x, inorder + y, postorder[idx]) - inorder;
    root = new node(postorder[idx++], makeTree(pivot + 1, y),
                    makeTree(x, pivot - 1));
    return root;
} //

void printTree(node *cand) {
    if (!cand) return;
    cout << cand->value << " ";
    printTree(cand->right);
    printTree(cand->left);
} // root -> right -> left 순 출력.

int main() {
    fastIO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        // 값을 거꾸로 넣어, root -> right -> left순회를 만든다.
        cin >> postorder[i];
    }
    node *root = makeTree(0, n - 1);
    printTree(root);
    return 0;
}
