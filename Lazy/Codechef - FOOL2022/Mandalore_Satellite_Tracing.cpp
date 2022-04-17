#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<vector<int>> bac(n);
    vector<pair<int, int>> w(n);
    for(int i = 0; i < n; i++) {
        string s;
        int a, b;
        cin >> s >> a >> b;
        w[i] = {a, b};
    }
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        bac[b].push_back(a);
    }
    int source = -1;
    int sink = -1;
    for(int i = 0; i < n; i++) {
        if((int)bac[i].size() == 0) source = i;
        if((int)adj[i].size() == 0) sink = i;
    }
    if(source == -1 || sink == -1) {
        int x = 3, y = 0;
        x /= y;
    }
    
    return 0;
}