#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, b;
    cin >> n >> m >> b;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int o = 1;
    while(o <= b) o <<= 1;
    o >>= 1; o--;
    // 1 --> Check if bipartite graph possible.

    vector <int> col(n, -1);
    bool pos = true;
    function<void(int, int)> CHECK = [&](int node, int color) -> void {
        col[node] = color;
        for(auto next : adj[node]) {
            if(col[next] == -1) CHECK(next, color ^ 1);
            else if(col[next] == col[node]) pos = false;
        }
    };

    CHECK(0, 0);
    if(pos) {
        cout << b << '\n';
        for(int i = 0; i < n; i++) {
            cout << (col[i] ? b : 0) << ' ';
        }
        return 0;
    }

    vector <pair<int, int>> back;
    vector<vector<int>> g(n);

    vector<int> d(n, -1); // depth.
    function<void(int, int, int)> DFS = [&](int node, int prev, int depth) -> void {
        d[node] = depth;
        for(auto next : adj[node]) {
            if(d[next] == -1) DFS(next, node, depth + 1);
            else if(next != prev && d[next] < d[node]) {
                if(d[node] % 2 == d[next] % 2) {
                    back.push_back({node, next});
                    g[node].push_back(next);
                    g[next].push_back(node);
                }
            }
        }
    };

    DFS(0, 0, 0);
    cout << o << '\n';
    vector <int> ans(n);
    for(int i = 0; i < n; i++) {
        assert(d[i] != -1);
        // ans[i] = (d[i] % 2 ? 1 : 0);
        ans[i] = d[i] % 2;
    }
    // for(auto i : back) ans[i] = 2;
    for(auto i : back) {
        // if(ans[i.second] != 2) ans[i.first] = 2;
        // cout << i.first + 1 << ' ' << col[i.first] << ' ' << i.second + 1 << ' ' << i.second << '\n';
    }

    // assert((int)back.size() == m - n + 1);

    vector <int> vv(n, -1);
    function<void(int, int)> COL2 = [&](int node, int color) -> void {
        vv[node] = color;
        // cerr << node + 1 << ' ';
        for(auto next : g[node]) {
            if(vv[next] == -1) COL2(next, color ^ 1);
            else if(vv[next] == vv[node]) pos = false;
        }
    };
    for(auto i : back) {
        if(vv[i.first] == -1) COL2(i.first, 0);
    }
    for(int i = 0; i < n; i++) {
        if(vv[i] == 1) ans[i] = 2;
    }


    vector <int> vis(n, false);
    function<void(int)> CHECK_TRI = [&](int node) -> void {
        vis[node] = true;
        for(auto next : adj[node]) {
            assert(ans[node] != ans[next]);
            if(!vis[next]) CHECK_TRI(next);
        }
    };
    CHECK_TRI(0);

    for(auto i : ans) {
        if(i == 0) cout << 0;
        if(i == 1) cout << o;
        if(i == 2) cout << b;
        cout << ' ';
    }
    return 0;
}