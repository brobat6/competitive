#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 100100
#define MOD 1000000007

int n, m, t1, t2, t3;
int arr[MAXN];
int st[4*MAXN];

int func(int a, int b) {
    return a|b;
}

void build(int v, int tl, int tr) {
    if(tl==tr) st[v] = 1ll<<arr[tl];
    else {
        int tm = (tl + tr)/2;
        build(v*2, tl, tm);
        build(v*2 + 1, tm + 1, tr);
        st[v] = func(st[v*2], st[v*2 + 1]); 
    }
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if(tl==tr) st[v] = 1ll<<new_val;
    else {
        int tm = (tl + tr)/2;
        if(pos <= tm) update(v*2, tl, tm, pos, new_val);
        else update(v*2 + 1, tm+1, tr, pos, new_val);
        st[v] = func(st[v*2], st[v*2 + 1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if(l > r) return 0;
    if(l==tl && r==tr) return st[v];
    int tm = (tl + tr)/2;
    return func(query(v*2, tl, tm, l, min(r, tm)), query(v*2 + 1, tm + 1, tr, max(l, tm+1), r));
}

void solve() {
    cin >> n >> m;
    forn(i, 0, n) cin >> arr[i];
    build(1, 0, n-1);
    forn(i, 0, m) {
        cin >> t1 >> t2 >> t3;
        if(t1==1) cout << __builtin_popcountll(query(1, 0, n-1, t2-1, t3-1)) << "\n";
        if(t1==2) update(1, 0, n-1, t2-1, t3);
    }
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