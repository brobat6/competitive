#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector <int> sz(n);
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    function<int(int, int)> dfs_sz = [&](int node, int prev) -> int {
        sz[node] = 1;
        for(auto next : adj[node]) {
            if(next == prev) continue;
            sz[node] += dfs_sz(next, node);
        }   
        return sz[node];
    };
    dfs_sz(0, 0);
    function<int(int, int)> find_centroid = [&](int node, int prev) -> int {
        for(auto next : adj[node]) {
            if(next == prev) continue;
            if(2*sz[next] > n) {
                return find_centroid(next, node);
            }
        }
        return node;
    };
    cout << find_centroid(0, 0) + 1;
    
    return 0;
}