#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<int, int>>> adj(n);
    map<pair<int, int>, int> edge;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        edge[{a, b}] = c;
        edge[{b, a}] = c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    cout << "Case #1: ";
    for(int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        int ans = 2*edge[{x, y}];
        for(auto nx : adj[x]) {
            if(edge[{nx.first, y}] > 0) {
                ans += min(edge[{nx.first, y}], nx.second);
            }
        }
        cout << ans << ' ';
    }
    
    return 0;
}