#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, q, b;
vector<vector<int>> adj;
int timer = 0;
map <int, int> t;

void dfs(int node, int prev) {
    t[timer++] = node;
    sort(adj[node].begin(), adj[node].end());
    for(auto next : adj[node]) {
        if(next != prev) {
            dfs(next, node);
        }
    }
}

class DSU {
public:
    int n;
    vector <int> p, sz;

    DSU(int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        sz.resize(n, 1);
    }

    int find(int x) {
        if(x == p[x]) return x;
        return p[x] = find(p[x]);
    }

    void unite(int a, int b) {
        int c = find(a);
        int d = find(b);
        if(d != c) {
            if(sz[c] < sz[d]) swap(c, d);
            p[d] = c;
            sz[c] += sz[d];
        }
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> q >> b;
    assert(n <= 2000);
    adj.resize(n);
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(0, 0);
    while(q--) {
        DSU d(n);
        int k;
        cin >> k;
        vector <int> pos(n, false);
        for(int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            for(int j = x; j <= y; j++) {
                pos[t[j]] = true;
            }
        }
        for(int i = 0; i < n; i++) {
            if(!pos[i]) continue;
            for(auto j : adj[i]) {
                if(!pos[j]) continue;
                d.unite(i, j);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(!pos[i]) continue;
            if(i == d.find(i)) ans++;
        }
        cout << ans << '\n';
    }
    
    return 0;
}