#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n);
        for(int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector <int> col(n, -1);
        col[0] = 0;
        queue<int> q;
        q.push(0);
        bool pos = true;
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            if(!pos) break;
            for(auto nx : adj[x]) {
                if(col[nx] == -1) {
                    col[nx] = col[x] ^ 1;
                    q.push(nx);
                } else if(col[nx] == col[x]) {
                    pos = false;
                    break;
                }
            }
        }
        cout << (pos ? 1 : 0) << '\n';
    }
    
    return 0;
}