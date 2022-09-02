// Ford-Fulkerson with Scaling, O(E * E * Log2(C))

#include <bits/stdc++.h>
using namespace std;

const long long INF = 1E18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<vector<long long>> capacity(n, vector<long long>(n, 0));
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        bool exists = false;
        for(auto nx : adj[a]) {
            if(nx == b) exists = true;
        }
        if(!exists) {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        capacity[a][b] += c;
    }
    long long ans = 0;

    vector<int> path;
    long long augment_value = 0;
    vector<bool> vis(n);
    vector<vector<int>> g(n); // current adjaceny list, based on the scaling factor.
    function<bool(int, long long)> DFS = [&](int node, long long bottleneck) -> bool {
        vis[node] = true;
        if(bottleneck == 0) return false;
        if(node == n - 1) {
            augment_value = bottleneck;
            path.push_back(node);
            return true;
        }
        for(auto next : g[node]) {
            if(!vis[next]) {
                bool pos = DFS(next, min(bottleneck, capacity[node][next]));
                if(pos) {
                    path.push_back(node);
                    return true;
                }
            }
        }    
        return false;
    };
    long long scaling = 1ll<<45; // extremely generous upper bound.
    while(scaling) {
        path.clear();
        fill(vis.begin(), vis.end(), false);
        augment_value = 0;
        for(int i = 0; i < n; i++) g[i].clear();
        for(int i = 0; i < n; i++) {
            for(auto nx : adj[i]) {
                if(capacity[i][nx] >= scaling) {
                    g[i].push_back(nx);
                }
            }
        }
        if(DFS(0, INF)) {
            ans += augment_value;
            reverse(path.begin(), path.end());
            for(int i = 1; i < (int)path.size(); i++) {
                capacity[path[i - 1]][path[i]] -= augment_value;
                capacity[path[i]][path[i - 1]] += augment_value;
            }
        }
        else scaling >>= 1;
    }
    cout << ans;
    
    return 0;
}