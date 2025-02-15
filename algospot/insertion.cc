#include <iostream>
#include <numeric>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, lehmer[50000], answer[50000];

struct Node {
    int key, priority, size;
    Node *left, *right;
    Node(const int &_key)
        : key(_key), priority(rand()), size(1), left(nullptr), right(nullptr) {}
    void setLeft(Node *_left) {
        left = _left;
        calcSize();
    }
    void setRight(Node *_right) {
        right = _right;
        calcSize();
    }
    void calcSize() {
        size = 1;
        if (left) size += left->size;
        if (right) size += right->size;
    }
}; // 트리의 element를 표현하는 Node 클래스

typedef pair<Node *, Node *> Nodepair;

Nodepair split(Node *root, int key) {
    if (root == nullptr) return make_pair(nullptr, nullptr);
    // 루트의 키가 입력 키보다 큼
    if (root->key > key) {
        Nodepair ls = split(root->left, key);
        root->setLeft(ls.second);
        return Nodepair(ls.first, root);
    }
    Nodepair rs = split(root->right, key);
    root->setRight(rs.first);
    return Nodepair(root, rs.second);
} // k를 기준으로 트리 분리

Node *insert(Node *root, Node *node) {
    if (root == nullptr) return node;
    if (root->priority < node->priority) {
        Nodepair splitted = split(root, node->key);
        node->setLeft(splitted.first);
        node->setRight(splitted.second);
        return node;
    } else if (root->key < node->key)
        root->setRight(insert(root->right, node));
    else
        root->setLeft(insert(root->left, node));
    return root;
} // 삽입

Node *merge(Node *a, Node *b) {
    if (a == nullptr) return b;
    if (b == nullptr) return a;
    if (a->priority < b->priority) {
        b->setLeft(merge(a, b->left));
        return b;
    }
    a->setRight(merge(a->right, b));
    return a;
} // 합치기

Node *erase(Node *root, int key) {
    if (root == nullptr) return nullptr;

    if (root->key == key) {
        Node *ret = merge(root->left, root->right);
        delete root;
        return ret;
    }
    if (root->key > key)
        root->setLeft(erase(root->left, key));
    else
        root->setRight(erase(root->right, key));
    return root;
} // 지우기

Node *findKth(Node *root, int k) {
    int l = root->left ? root->left->size : 0;
    if (k < l + 1)
        return findKth(root->left, k);
    else if (k == l + 1)
        return root;
    return findKth(root->right, k - l - 1);
} // k번째 수 찾기

int countLessThan(Node *root, int key) {
    if (root == nullptr) return 0;
    if (root->key >= key) {
        return countLessThan(root->left, key);
    }
    int ls = root->left ? root->left->size : 0;
    return ls + 1 + countLessThan(root->right, key);
}

int main() {
    fastIO;
    int C;
    cin >> C;
    while (C--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> lehmer[i];
        }
        Node *root = nullptr;
        for (int i = 1; i <= n; i++) {
            root = insert(root, new Node(i));
        }
        for (int i = n - 1; i >= 0; i--) {
            Node *k = findKth(root, i + 1 - lehmer[i]);
            answer[i] = k->key;
            root = erase(root, k->key);
        }
        for (int i = 0; i < n; i++) {
            cout << answer[i] << " ";
        }
        cout << "\n";
    }
    return 0;
} // 트립 연습 문제, 펜웍 트리로 풀 수 있다.