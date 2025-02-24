#include <cstring>
#include <iostream>
#include <queue>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

struct TrieNode {
    TrieNode *alphabet[26];
    TrieNode *fail;
    int id;
    bool terminal;
    static int counter;
    TrieNode() : fail(0), id(counter++), terminal(0) {
        memset(alphabet, 0, sizeof(alphabet));
    }
    ~TrieNode() {
        for (int i = 0; i < 26; i++) {
            if (alphabet[i]) delete alphabet[i];
        }
    }
};

int TrieNode::counter = 0;
TrieNode *root;
string s;

void insert() {
    TrieNode *ptr = root;
    for (char &c : s) {
        int k = c - 'a';
        if (!ptr->alphabet[k]) ptr->alphabet[k] = new TrieNode();
        ptr = ptr->alphabet[k];
    }
    ptr->terminal = 1;
}

void calFailFunction() {
    queue<TrieNode *> q;
    root->fail = root; // 루트의 실패는 루트
    q.push(root);
    while (!q.empty()) {
        TrieNode *here = q.front();
        q.pop();
        for (int i = 0; i < 26; i++) {
            TrieNode *child = here->alphabet[i];
            if (!child) continue;
            if (here == root)
                child->fail = root;
            else {
                TrieNode *t = here->fail;
                while (t != root && !t->alphabet[i]) {
                    t = t->fail;
                }
                if (t->alphabet[i]) t = t->alphabet[i];
                child->fail = t;
            }
            child->terminal |= child->fail->terminal;
            q.push(child);
        }
    }
}

// 각 노드는 고유한 id[0, 1000]를 가진다.
int DP[1001][101];
int function(TrieNode *node, int depth) {
    int &ret = DP[node->id][depth];
    if (ret != -1) return ret;
    if (node->terminal) return ret = 0;
    if (depth == 0) return ret = 1;
    ret = 0;
    for (int i = 0; i < 26; i++) {
        TrieNode *t = node;
        while (t != root && !t->alphabet[i])
            t = t->fail;
        if (t->alphabet[i]) t = t->alphabet[i];
        ret += function(t, depth - 1);
        ret %= 10007;
    }
    return ret;
}

int main() {
    fastIO;
    int C, n, m;
    cin >> C;
    while (C--) {
        cin >> n >> m;
        TrieNode::counter = 0;
        root = new TrieNode();
        for (int i = 0; i < m; i++) {
            cin >> s;
            insert();
        }
        calFailFunction();
        memset(DP, -1, sizeof(DP));
        cout << function(root, n) << "\n";
        delete root;
    }
    return 0;
}