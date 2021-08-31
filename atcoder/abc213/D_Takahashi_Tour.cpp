#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

int n;
vector <int> adj[MAXN];
bool visited[MAXN];

void dfs(int node) {
    cout << node + 1 << " ";
    visited[node] = true;
    for(int next: adj[node]) {
        if(!visited[next]) {
            dfs(next);
            cout << node + 1 << " ";
        }
    }
}

void solve() {
    cin >> n;
    forn(i, 0, n) visited[i] = false;
    int t1, t2;
    forn(i, 0, n-1) {
        cin >> t1 >> t2;
        t1--; t2--;
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
    }
    forn(i, 0, n) sort(adj[i].begin(), adj[i].end());
    dfs(0);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // int t; cin >> t; while(t--)
    {solve();}
    return 0;
}