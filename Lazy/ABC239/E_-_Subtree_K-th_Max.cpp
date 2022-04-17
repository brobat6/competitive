#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 100100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

int n, q;
vector <int> x;
vector <int> adj[MAXN];
vector <vector<int>> ans;
int t1, t2;

void dfs(int node, int prev) {
    // ans[node].push_back(x[node]);
    for(auto next : adj[node]) {
        if(next != prev) dfs(next, node);
    }
    priority_queue<int> pq;
    pq.push(x[node]);
    for(auto next : adj[node]) {
        if(next == prev) continue;
        for(auto j : ans[next]) {
            pq.push(j);
        }
    }
    int j = 0;
    while(j < 20 && !pq.empty()) {
        ans[node].push_back(pq.top());
        pq.pop();
        j++;
    }
    if(j < 20) {
        ans[node].push_back(-1);
        j++;
    }
    sort(ans[node].begin(), ans[node].end(), greater<int>());
}

void solve() {
    cin >> n >> q;
    x.resize(n);
    ans.resize(n);
    forn(i, 0, n) {
        cin >> x[i];
    }
    forn(i, 0, n - 1) {
        cin >> t1 >> t2;
        --t1; --t2;
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
    }
    dfs(0, 0);
    forn(i, 0, q) {
        cin >> t1 >> t2;
        --t1; --t2;
        cout << ans[t1][t2] << endl;
    }
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