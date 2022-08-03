#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, q, l;
vector<vector<int>> adj, up;
vector <int> s, e;
int timer;
vector<int> tin, tout;
int ans = 0;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

int dfs_final(int node, int prev) {
    int x = s[node];
    for(auto next : adj[node]) {
        if(next != prev) {
            x += dfs_final(next, node);
        }
    }
    ans = max(ans, x - e[node]);
    return x - 2*e[node];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("maxflow.in", "r", stdin);
    freopen("maxflow.out", "w", stdout);
    
    cin >> n >> q;
    adj.resize(n);
    s.resize(n, 0);
    e.resize(n, 0);
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    preprocess(0);
    for(int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        int z = lca(x, y);
        s[x]++;
        e[z]++;
        s[y]++;
    }
    dfs_final(0, 0);
    cout << ans;
    
    return 0;
}