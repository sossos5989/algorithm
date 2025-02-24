#include <cstring>
#include <iostream>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m, f;
string input;

struct TrieNode {
    TrieNode *alphabet[26];
    bool terminal;
    int max_f;
    string best;
    TrieNode() : terminal(false), max_f(0), best("") {
        memset(alphabet, 0, sizeof(alphabet));
    }
    ~TrieNode() {
        for (int i = 0; i < 26; i++) {
            if (alphabet[i] != nullptr) {
                delete alphabet[i];
            }
        }
    }
};

TrieNode *root;
void makeTree(TrieNode *tree, int depth) {
    int k = input[depth] - 'A';
    if (tree->alphabet[k] == nullptr) tree->alphabet[k] = new TrieNode();
    if (tree->max_f < f || (tree->max_f == f && tree->best > input)) {
        tree->best = input;
        tree->max_f = f;
    }
    if (input.size() == depth) {
        tree->terminal = true;
        return;
    }
    makeTree(tree->alphabet[k], depth + 1);
}

int typing(TrieNode *tree, int depth) {
    if (depth + 1 == input.size()) return input.size();
    if (tree->best == input) return depth + 1;
    int k = input[depth] - 'A';
    if (tree->alphabet[k] == nullptr) return input.size();
    return typing(tree->alphabet[k], depth + 1);
}

int main() {
    fastIO;
    int C;
    cin >> C;
    while (C--) {
        cin >> n >> m;
        root = new TrieNode();
        root->max_f = 1234567;
        for (int i = 0; i < n; i++) {
            cin >> input >> f;
            makeTree(root, 0);
        }
        int sum = 0;
        for (int i = 0; i < m; i++) {
            cin >> input;
            sum += typing(root, 0);
        }
        cout << sum + m - 1 << "\n";
        delete root;
    }
    return 0;
}