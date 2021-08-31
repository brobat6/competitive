#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 100100
#define MOD 1000000007

int n, t1, t2;
vector<int> adj[MAXN];
int dp[MAXN][2]; // 0--> Black, 1--> White.

/*
Thoughts - 
dp[node][0] and dp[node][1] ---> Multiply the answer of their subtrees.
*/

void dfs(int node, int prev) {
    for(auto next : adj[node]) {
        if(next==prev) continue;
        dfs(next, node);
        dp[node][0] = (dp[node][0] * dp[next][1]) % MOD;
        dp[node][1] = (dp[node][1] * (dp[next][0] + dp[next][1])) % MOD;
    }
}

void solve() {
    cin >> n;
    forn(i, 0, n-1) {
        cin >> t1 >> t2;
        adj[--t1].push_back(--t2);
        adj[t2].push_back(t1);
    }
    forn(i, 0, n) forn(j, 0, 2) dp[i][j] = 1;
    dfs(0, 0);
    cout << (dp[0][0] + dp[0][1])%MOD;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}