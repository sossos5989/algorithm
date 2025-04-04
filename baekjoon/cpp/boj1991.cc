#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

pair<int, int> adj[26];

void pre(int x) {
    cout << (char)(x + 'A');
    if (adj[x].first != -1) pre(adj[x].first);
    if (adj[x].second != -1) pre(adj[x].second);
}

void in(int x) {
    if (adj[x].first != -1) in(adj[x].first);
    cout << (char)(x + 'A');
    if (adj[x].second != -1) in(adj[x].second);
}

void post(int x) {
    if (adj[x].first != -1) post(adj[x].first);
    if (adj[x].second != -1) post(adj[x].second);
    cout << (char)(x + 'A');
}

int main() {
    fastIO;
    int n;
    char a, b, c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        adj[a - 'A'] = {-1, -1};
        if (b != '.') adj[a - 'A'].first = b - 'A';
        if (c != '.') adj[a - 'A'].second = c - 'A';
    }
    pre(0);
    cout << "\n";
    in(0);
    cout << "\n";
    post(0);
    return 0;
}