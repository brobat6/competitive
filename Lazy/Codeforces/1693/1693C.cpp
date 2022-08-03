#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
vector<vector<pair<int, int>>> adj;
vector<multiset<int>> ms;
const int INF = (int)1E18;

void dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    vector <int> cnt(n, 0);
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;
        d[v] -= cnt;
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            } 
            else if(d[v] + len == d[to]) {
                cnt[to] += ms[to].count(v);
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;

    ms.resize(n);
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        ms[x].insert(y);
    }
    adj.resize(n);
    for(int i = 0; i < n; i++) {
        set <int> temp;
        int x = ms[i].size();
        for(auto j : ms[i]) temp.insert(j);
        for(auto j : temp) {
            int y = ms[i].count(j);
            // adj[i].push_back({j, x - y + 1});
            adj[j].push_back({i, x - y + 1});
        }
    }
    vector <int> d(n), p(n);
    dijkstra(n - 1, d, p);
    cout << d[0];
    
    return 0;
}