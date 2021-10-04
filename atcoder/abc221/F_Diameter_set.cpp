#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 998244353;

int n, t1, t2, d;
vector <int> adj[MAXN];
vector <pair<int, int>> path; // The length and frequency of a path from leaf to node.
vector <pair<int, int>> ans; // The length and freq. of a path with highest point at node.

void dfs(int curr, int prev) {
    if(adj[curr].size()==1 && curr != 0) {
        path[curr] = {1, 1};
        ans[curr] = {1, 1};
        return;
    }
    vector <pair<int, int>> temp;
    for(auto next : adj[curr]) {
        if(next == prev) continue;
        dfs(next, curr);
        temp.push_back(path[next]);
    }
    sort(temp.begin(), temp.end(), greater<pair<int, int>>());
    if(temp.size() == 1) {
        path[curr] = {temp[0].first + 1, temp[0].second};
        ans[curr] = {temp[0].first + 1, temp[0].second};
        return;
    }
    if(temp[0].first == temp[1].first) {
        int t = 1, u = 1;
        for(auto i : temp) {
            if(i.first == temp[0].first) {
                t = (t * (i.second + 1)) % MOD;
                u = (u + i.second) % MOD;
            }
        }
        path[curr] = {temp[0].first + 1, (u - 1 + MOD) % MOD};
        ans[curr] = {temp[0].first * 2, (t - u + MOD) % MOD};
    }
    else {
        int t = 0;
        for(auto i : temp) {
            if(i.first == temp[1].first) {
                t = (t + i.second) % MOD;
            }
        }
        path[curr] = {temp[0].first + 1, temp[0].second};
        ans[curr] = {temp[0].first + temp[1].first, (temp[0].second * t) % MOD};
    }
}


void solve() {
    cin >> n;
    path.resize(n);
    ans.resize(n);
    forn(i, 0, n-1) {
        cin >> t1 >> t2;
        adj[--t1].push_back(--t2);
        adj[t2].push_back(t1);
    }
    dfs(0, 0);
    d = 0;
    forn(i, 0, n) d = max(d, ans[i].first);
    int x = 0;
    forn(i, 0, n) {
        if(ans[i].first == d) {
            x = (x + ans[i].second) % MOD;
        }
    }
    cout << x << endl;
    cerr << ans[2].second << " " << ans[0].second << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}