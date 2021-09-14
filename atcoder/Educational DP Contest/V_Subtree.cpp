#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 100100

/*
dp[x] = Colour x black, and then find the number of ways to colour its subtrees.
dp[x] = (1 + dp[a])(1 + dp[b])(1 + dp[c]).... over all children of x

pd[x] = Colour x black, and then find the number of ways to colour its parent trees.
pd[x] = (1 + pd[y]) * (1 + dp[A])(1 + dp[B]).... over all OTHER children of y.
pd[root] = 0.
Ans. dp[x]*(pd[x] + 1)
Calculate pd using segment tree.

NOTE - JUST REALIZED (AFTER AC) THAT PD CAN BE CALCULATED IN O(N) VIA PREFIX AND SUFFIX SUMS.
*/

int n, MOD, t1, t2;
vector <int> adj[MAXN];
int dp[MAXN];
int pd[MAXN];

void dfs(int node, int prev) {
    vector<int> arr;
    for(auto next : adj[node]) {
        if(next != prev) dfs(next, node);
    }
    for(auto next : adj[node]) {
        if(next != prev) {
            dp[node] = (dp[node] * (1 + dp[next])) % MOD;
            arr.push_back(next);
        }
    }
    int x = arr.size();
    if(x < 2) return;
    else {
        int pre[x];
        int suff[x];
        pre[0] = 1 + dp[arr[0]];
        forn(i, 1, x) {
            pre[i] = (pre[i-1] * (1 + dp[arr[i]])) % MOD;
        }
        suff[x - 1] = 1 + dp[arr[x-1]];
        for(int i = x-2; i>=0; i--) {
            suff[i] = (suff[i+1] * (1 + dp[arr[i]])) % MOD;
        }
        forn(i, 0, x) {
            if(i==0) pd[arr[i]] = suff[1];
            else if(i==x-1) pd[arr[i]] = pre[x-2];
            else {
                pd[arr[i]] = (pre[i-1] * suff[i+1]) % MOD;
            }
        }
    }
}

void dfs_parent(int node, int prev) {
    pd[node] = (pd[node] * (1 + pd[prev])) % MOD;
    for(auto next : adj[node]) {
        if(next == prev) continue;
        dfs_parent(next, node);
    }
}

void solve() {
    cin >> n >> MOD;
    forn(i, 0, n - 1) {
        cin >> t1 >> t2;
        adj[--t1].push_back(--t2);
        adj[t2].push_back(t1);
    }
    forn(i, 0, n) dp[i] = pd[i] = 1;
    pd[0] = 0;
    dfs(0, 0);
    dfs_parent(0, 0);
    forn(i, 0, n) cout << (dp[i] * (pd[i] + 1)) % MOD << endl;
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