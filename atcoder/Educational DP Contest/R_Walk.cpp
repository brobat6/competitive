#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

int n, k;
vector<vector<int>> G;
vector<vector<int>> res;

void multiply(vector<vector<int>> &a, vector<vector<int>> &b) {
    vector<vector<int>> prod(n, vector<int>(n));
    forn(i, 0, n) forn(j, 0, n) prod[i][j] = 0;
    forn(i, 0, n) forn(j, 0, n) forn(k, 0, n) {
        prod[i][j] = (prod[i][j] + (a[i][k]*b[k][j])) % MOD;
    }
    forn(i, 0, n) forn(j, 0, n) a[i][j] = prod[i][j];
}

void func(int x) {
    while(x > 0) {
        if(x & 1) multiply(res, G);
        multiply(G, G);
        x >>= 1;
    }
}

void solve() {
    cin >> n >> k;
    G.resize(n);
    res.resize(n);
    forn(i, 0, n) {G[i].resize(n); res[i].resize(n);}
    forn(i, 0, n) forn(j, 0, n) cin >> G[i][j];
    forn(i, 0, n) forn(j, 0, n) {
        if(i==j) res[i][j] = 1;
        else res[i][j] = 0;
    }
    func(k);
    int ans = 0;
    forn(i, 0, n) forn(j, 0, n) ans = (ans + res[i][j]) % MOD;
    cout << ans << endl;
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