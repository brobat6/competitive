#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

int n;
int height[MAXN], st[4*MAXN], beauty[MAXN], dp[MAXN];

int query(int v, int tl, int tr, int l, int r) {
    if(l > r) return 0; // Return appropriate value, for example INF for find_min.
    if(l==tl && r==tr) return st[v];
    int tm = (tl + tr)/2;
    return max(query(v*2, tl, tm, l, min(r, tm)), query(v*2 + 1, tm + 1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if(tl==tr) st[v] = new_val; // Assign value here.
    else {
        int tm = (tl + tr)/2;
        if(pos <= tm) update(v*2, tl, tm, pos, new_val);
        else update(v*2 + 1, tm+1, tr, pos, new_val);
        st[v] = max(st[v*2], st[v*2 + 1]);
    }
}

void solve() {
    cin >> n;
    forn(i, 0, n) cin >> height[i];
    forn(i, 0, n) cin >> beauty[i];
    forn(i, 0, n) {
        dp[i] = query(1, 0, n-1, 0, height[i] - 2) + beauty[i];
        update(1, 0, n-1, height[i] - 1, dp[i]);
    }
    cout << *max_element(dp, dp+n);
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