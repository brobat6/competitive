#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = (ll)1E18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, b;
    cin >> n >> b;
    vector <int> c(n), d(n);
    vector <vector<int>> adj(n);
    for(int i = 0; i < n; i++) {
        cin >> c[i] >> d[i];
        if(i) {
            int x; cin >> x; --x;
            adj[i].push_back(x);
            adj[x].push_back(i);
        }
    }
    vector<int> sz(n, 0);
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(2, vector<ll>(n + 1, INF)));
    // dp[node][0][chosen] --> Minimum price to buy "chosen" number of items assuming no discount
    // dp[node][1][chosen] --> Minimum price to buy "chosen" number of items assuming discount


    function<int(int, int)> DFS = [&](int node, int prev) -> int {
        int size = 1;
        vector <int> child;
        for(auto next : adj[node]) {
            if(next != prev) {
                child.push_back(DFS(next, node));
                size += sz[next];
            }
        }
        int mx = *max_element(child.begin(), child.end());
        for(auto nx : child) {
            if(mx == nx) continue;
            // merge nx with mx.
            for(int i = sz[nx]; i >= 0; i--) {
                
            }
        }
        sz[node] = size;
        return mx;
    };
    
    return 0;
}