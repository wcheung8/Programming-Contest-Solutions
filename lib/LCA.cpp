//https://open.kattis.com/problems/tourists/
#include "bits/stdc++.h"
using namespace std;

const int MAXN = 200050;
const int LN = 20;

int n;
vector<int> adj[MAXN];
int anc[LN][MAXN]; // anc[i][u] = 2^ith ancestor of the node u
int depth[MAXN]; // depth[u] = depth of the node u

void dfs(int u, int p = 1) {
    
    anc[0][u] = p;
    for (int i = 1; i < LN; i++) {
        anc[i][u] = anc[i - 1][anc[i - 1][u]];
    }
    
    for (int v: adj[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    // Bring both u and v to the same depth by fast-jumping.
    for (int i = LN - 1; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = anc[i][u];
        }
    }
    // At this point we're sure that depth[u] = depth[v].
    // So if u becomes equal to v, we know that u itself is the LCA.
    if (u == v) {
        return u;
    }
    // Otherwise, we do a binary search to find the maximum integer k
    // such that the kth ancestor of u is NOT equal to the kth ancestor of v.
    for (int i = LN - 1; i >= 0; i--) {
        if (anc[i][u] != anc[i][v]) {
            u = anc[i][u];
            v = anc[i][v];
        }
    }
    // The parent of this kth ancestor is the required LCA.
    return anc[0][u];
}

inline int dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)] + 1;
}

int main() {
    ios :: sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 2 * i; j <= n; j += i) {
            res += dist(i, j);
        }
    }
    cout << res << endl;
}