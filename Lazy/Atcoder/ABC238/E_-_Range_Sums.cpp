#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

void solve() {
    int n, p;
    cin >> n >> p;
    vector <int> adj[n + 1];
    vector <bool> visited(n + 1, false);
    forn(i, 0, p) {
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b);
        adj[b].push_back(a-1);
    }
    queue <int> q;
    q.push(0);
    visited[0] = true;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(auto next : adj[curr]) {
            if(!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
    cout << (visited[n] ? "Yes" : "No");
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T = 1;
    // cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}