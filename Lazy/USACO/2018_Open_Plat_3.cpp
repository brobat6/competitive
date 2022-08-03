#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, l;
vector<vector<int>> adj, up;
int timer;
vector<int> tin, tout;
int m;
map<pair<int, int>, int> edge;
vector<multiset<pair<int, int>>> ms, ms_dist;
vector <int> ans;

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

// small to large merging
int dfs_final(int node, int prev) {
    vector <int> p;
    p.push_back(node);
    for(auto next : adj[node]) {
        if(next != prev) {
            p.push_back(dfs_final(next, node));
        }
    }
    sort(p.begin(), p.end(), [&](int x, int y) {
        return (int)ms[x].size() > (int)ms[y].size();
    });
    for(int i = 1; i < (int)p.size(); i++) {
        for(auto j : ms[p[i]]) ms[p[0]].insert(j);
        for(auto j : ms_dist[p[i]]) ms_dist[p[0]].insert(j);
        ms[p[i]].clear();
        ms_dist[p[i]].clear();
    }
    int q = p[0];
    while(!ms[q].empty()) {
        auto x = ms[q].lower_bound({node, -1});
        if(x == ms[q].end() || (*x).first != node) break;
        ms_dist[q].erase({(*x).second, (*x).first});
        ms[q].erase(x);
    }
    if(node == 0) return 0;
    if(ms[q].empty()) {
        ans[edge[{node, prev}]] = -1;
    } else {
        ans[edge[{node, prev}]] = (*ms_dist[q].begin()).first;
    }
    return q;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("disrupt.in", "r", stdin);
    freopen("disrupt.out", "w", stdout);
    
    cin >> n >> m;
    adj.resize(n);
    ms.resize(n);
    ms_dist.resize(n);
    ans.resize(n - 1);
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        edge[{x, y}] = edge[{y, x}] = i;
    }
    preprocess(0);
    for(int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        --x; --y;
        int r = lca(x, y);
        ms[x].insert({r, z});
        ms[y].insert({r, z});
        ms_dist[x].insert({z, r});
        ms_dist[y].insert({z, r});
    }
    dfs_final(0, 0);
    for(int i = 0; i < n - 1; i++) {
        cout << ans[i] << '\n';
    }
    
    return 0;
}