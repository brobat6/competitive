#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 800100;
const int MOD = 1000000007;

int n, l, t1, t2;
vector <int> adj[MAXN];
int parent[MAXN], depth[MAXN], warp[MAXN];
map <int, bool> safe; // is edge between safe[i] and safe[parent[i]] safe or not?
int timer;
vector<int> tin, tout;
vector<vector<int>> up;
map<int, vector<int>> f; // m[3] = {1, 7, 9, 12} --> These are the nodes with frequency 3.
// n/2 ---> sum cannot be more than n. 

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

void dfs_dist(int node, int prev, int d) {
    parent[node] = prev;
    depth[node] = d;
    for(auto next : adj[node]) {
        if(next == prev) continue;
        dfs_dist(next, node, d + 1);
    }
}

void pre() {
    cin >> n;
    forn(i, 0, n) {
        adj[i].clear();
        depth[i] = -1;
        parent[i] = -1;
        warp[i] = -1;
    }
    safe.clear(); f.clear();
    tin.resize(n); tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    forn(i, 0, n-1) {
        cin >> t1 >> t2;
        adj[--t1].push_back(--t2);
        adj[t2].push_back(t1);
    }
    forn(i, 0, n) {
        cin >> t1;
        f[t1].push_back(i);
    }
    forn(i, 0, n) {
        safe[i] = true;
    }
}

void block(int from, int to) {
    if(depth[from] < depth[to]) return;
    if(from==to) return;
    safe[from] = false;
    // Now update warp[from].
    if(warp[from] == -1) {
        warp[from] = to;
        block(parent[from], to);
    }
    else if(depth[warp[from]] > depth[to]) {
        int t = warp[from];
        warp[from] = to;
        block(t, to);
    }
    else {
        return;
    }

}

void solve() {
    pre();
    dfs_dist(0, 0, 0);
    dfs(0, 0);
    // cout << lca(5, 0);
    for(auto i : f) {
        // First find lca of all values in f.
        int temp = i.second[0];
        forn(j, 1, i.second.size()) temp = lca(temp, i.second[j]);
        forn(j, 0, i.second.size()) {
            // Block the roads from i.second[j] to temp.
            block(i.second[j], temp);
        }
    }
    int ans = 0;
    for(auto i : safe) {
        if(i.first == 0) continue;
        if(i.second) ans++;
    }
    cout << ans << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("chainblock_validation_input.txt", "r", stdin);
    // freopen("output22.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    forn(I, 1, T + 1) {
        cout << "Case #" << I << ": ";
        solve();
    }

    return 0;
}