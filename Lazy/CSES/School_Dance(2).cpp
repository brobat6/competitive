// Bipartite Matching using Ford-Fulkerson in O(V * E) - better runtime than Dinic's!

#include <bits/stdc++.h>
using namespace std;

class FordFulkerson {
public:
    const long long FLOW_INF = 1E18;
    vector<vector<int>> adj; 
    vector<vector<long long>> capacity;
    int n; // number of nodes.
    int s; // source
    int t; // sink
    vector <int> path; // stores path at the end of a DFS
    vector <bool> vis; // visited array needed for every DFS
    long long augment_value; // bottleneck value for a DFS

    FordFulkerson(int _n, int _s, int _t) : n(_n), s(_s), t(_t) {
        adj.resize(n);
        capacity.resize(n, vector<long long>(n, 0));
        vis.resize(n);
    }

    void add_edge(int from, int to, long long cap) {
        adj[from].push_back(to);
        adj[to].push_back(from);
        capacity[from][to] += cap;
    }

    bool dfs(int node, long long bottleneck) {
        vis[node] = true;
        if(bottleneck == 0) return false;
        if(node == n - 1) {
            augment_value = bottleneck;
            path.push_back(node);
            return true;
        }
        for(auto next : adj[node]) {
            if(!vis[next] && capacity[node][next]) {
                bool pos = dfs(next, min(bottleneck, capacity[node][next]));
                if(pos) {
                    path.push_back(node);
                    return true;
                }
            }
        }
        return false;
    }

    long long flow() {
        long long ans = 0;
        while(true) {
            path.clear();
            fill(vis.begin(), vis.end(), false);
            augment_value = 0;
            if(dfs(0, FLOW_INF)) {
                ans += augment_value;
                reverse(path.begin(), path.end());
                for(int i = 1; i < (int)path.size(); i++) {
                    capacity[path[i - 1]][path[i]] -= augment_value;
                    capacity[path[i]][path[i - 1]] += augment_value;
                }
            } else break;
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    FordFulkerson f(n + m + 2, 0, n + m + 1);
    for(int i = 1; i <= n; i++) {
        f.add_edge(0, i, 1);
    }
    for(int i = n + 1; i <= n + m; i++) {
        f.add_edge(i, n + m + 1, 1);
    }
    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        f.add_edge(x, n + y, 1);
    }
    cout << f.flow() << '\n';
    for(int i = 1; i <= n; i++) {
        for(int j = n + 1; j <= n + m; j++) {
            if(f.capacity[j][i]) {
                cout << i << ' ' << j - n << '\n';
            }
        }
    }
    
    return 0;
}