#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n, m;
vector<vector<int>> adj, bac;
vector<int> state;
vector<int> vis;

void bfs() {
    queue <int> q;
    for(int i = 0; i < n; i++) {
        if(vis[i] == 1) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int curr = q.front();
        cerr << curr << endl;
        q.pop();
        for(auto next : bac[curr]) {
            if(vis[next] == 0) {
                q.push(next);
                vis[next] = 1;
            }
        }
    }
}

void dfs(int node) {
    state[node] = 1;
    for(auto next : adj[node]) {
        if(state[next] == 1) {
            vis[next] = 1;
            continue;
        }
        if(state[next] == 0) {
            dfs(next);
        }
    }
    state[node] = 2;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    adj.resize(n); bac.resize(n);
    state.resize(n); vis.resize(n);
    for(int i = 0; i < n; i++) {
        adj[i].clear();
        bac[i].clear();
        state[i] = 0;
        vis[i] = 0;
    }
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        bac[b].push_back(a);
    }
    for(int i = 0; i < n; i++) {
        if(state[i] == 0) dfs(i);
    }
    bfs();
    cout << accumulate(vis.begin(), vis.end(), 0ll);
    
    return 0;
}