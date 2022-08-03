#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

#define pi pair<int, int>
#define fs first
#define sn second

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    const int INF = 1E18;
    int n, m, k, l;
    cin >> n >> m >> k >> l;
    vector <int> a(n);
    vector <pi> dist(n, {INF, -1});
    vector <pi> dist2(n, {INF, -1});
    for(int i = 0; i < n; i++) {
        cin >> a[i]; --a[i];
    }
    for(int i = 0; i < l; i++) {
        int x; cin >> x; --x;
        dist[x] = {0, a[x]};
    }
    vector<vector<pi>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        --u; --v;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    {
        set <pi> q;
        for(int i = 0; i < n; i++) {
            if(dist[i].first == 0) {
                q.insert({dist[i].first, i});
            }
        }
        while(!q.empty()) {
            int curr = q.begin()->second;
            q.erase(q.begin());
            for(auto next : adj[curr]) {
                int to = next.first;
                int len = next.second;
                if(dist[curr].first + len < dist[to].first) {
                    q.erase({dist[to].first, to});
                    dist[to].first = dist[curr].first + len;
                    dist[to].second = dist[curr].second;
                    q.insert({dist[to].first, to});
                }
            }
        }
    }
    for(int curr = 0; curr < n; curr++) {
        for(auto next : adj[curr]) {
            int to = next.first;
            int len = next.second;
            if(dist[to].second == dist[curr].second) continue;
            if(dist[curr].first + len < dist2[to].first) {
                dist2[to].first = dist[curr].first + len;
                dist2[to].second = dist[curr].second;
            }
        }
    }
    {
        set <pi> q;
        for(int i = 0; i < n; i++) {
            if(dist2[i].first < INF) {
                q.insert({dist2[i].first, i});
            }
        }
        while(!q.empty()) {
            int curr = q.begin()->second;
            q.erase(q.begin());
            for(auto next : adj[curr]) {
                int to = next.first;
                int len = next.second;
                if(dist[to].second == dist2[curr].second) continue;
                if(dist2[curr].first + len < dist2[to].first) {
                    q.erase({dist2[to].first, to});
                    dist2[to].first = dist2[curr].first + len;
                    dist2[to].second = dist2[curr].second;
                    q.insert({dist[to].first, to});
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(dist[i].first == INF) dist[i].first = -1;
        if(dist2[i].first == INF) dist2[i].first = -1;
    }
    for(int i = 0; i < n; i++) {
        if(dist[i].second == a[i]) cout << dist2[i].first << " ";
        else cout << dist[i].first << " ";
    }
    
    return 0;
}