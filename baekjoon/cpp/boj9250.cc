#include <cstring>
#include <iostream>
#include <queue>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n;
string s;

struct TrieNode {
    TrieNode *alphabet[26], *failure;
    bool terminal;
    TrieNode() : failure(0), terminal(0) {
        memset(alphabet, 0, sizeof(alphabet));
    }
    ~TrieNode() {
        for (int i = 0; i < 26; i++) {
            if (alphabet[i]) delete alphabet[i];
        }
    }
};

TrieNode *root;
void makeNode(TrieNode *node, int depth) {
    if (depth == s.size()) {
        node->terminal = true;
        return;
    }
    int k = s[depth] - 'a';
    if (!node->alphabet[k]) node->alphabet[k] = new TrieNode();
    makeNode(node->alphabet[k], depth + 1);
}

void insertString() {
    TrieNode *current = root;
    for (char c : s) {
        int k = c - 'a';
        if (!current->alphabet[k]) {
            current->alphabet[k] = new TrieNode();
        }
        current = current->alphabet[k];
    }
    current->terminal = true;
}

void computeFailure() {
    queue<TrieNode *> q;
    root->failure = root;
    q.push(root);
    while (!q.empty()) {
        TrieNode *here = q.front();
        q.pop();
        for (int i = 0; i < 26; i++) {
            TrieNode *child = here->alphabet[i];
            if (!child) continue;
            if (here == root)
                child->failure = root;
            else {
                TrieNode *t = here->failure;
                while (t != root && !t->alphabet[i]) {
                    t = t->failure;
                }
                if (t->alphabet[i]) t = t->alphabet[i];
                child->failure = t;
            }
            child->terminal |= child->failure->terminal;
            q.push(child);
        }
    }
} // 이거 중요. 점화식을 이해하는게 first

bool ahoSearch() {
    TrieNode *current = root;
    for (char c : s) {
        int k = c - 'a';
        while (current != root && !current->alphabet[k])
            current = current->failure;
        if (current->alphabet[k]) current = current->alphabet[k];
        if (current->terminal) return true;
    }
    return false;
} // 개선. 실패하지 않을 때까지 iterative 방식으로 구현할 수 있다.

int main() {
    fastIO;
    cin >> n;
    root = new TrieNode();
    while (n--) {
        cin >> s;
        insertString();
    }
    computeFailure();
    cin >> n;
    while (n--) {
        cin >> s;
        cout << (ahoSearch() ? "YES\n" : "NO\n");
    }
    delete root;
    return 0;
}