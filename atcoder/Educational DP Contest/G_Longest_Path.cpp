#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 100100
#define MOD 1000000007

int n, m, t1, t2;
vector <int> adj[MAXN];
int visited[MAXN];

void dfs(int node) {
    visited[node] = 0;
    int x = 0;
    for(auto next : adj[node]) {
        if(visited[next] == -1) {
            dfs(next);
        }
        x = max(x, visited[next]);
    }
    visited[node] = 1 + x;
}

void solve() {
    cin >> n >> m;
    forn(i, 0, m) {
        cin >> t1 >> t2;
        adj[--t1].push_back(--t2);
    }
    forn(i, 0, n) visited[i] = -1;
    forn(i, 0, n) if(visited[i] == -1) dfs(i);
    cout << *max_element(visited, visited + n) - 1;
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