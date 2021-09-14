#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

int func(int a, int b) {
    // return a + b; // Segment tree for the sum
    // return min(a, b); // Segment tree for the minimum
}

int query(vector<int> &st, int v, int tl, int tr, int l, int r) {
    if(l > r) return 1000000000; // Return appropriate value, for example INF for find_min.
    if(l==tl && r==tr) return st[v];
    int tm = (tl + tr)/2;
    return func(query(st, v*2, tl, tm, l, min(r, tm)), query(st, v*2 + 1, tm + 1, tr, max(l, tm+1), r));
}

void update(vector<int> &st, int v, int tl, int tr, int pos, int new_val) {
    if(tl==tr) st[v] = new_val; // Assign value here.
    else {
        int tm = (tl + tr)/2;
        if(pos <= tm) update(st, v*2, tl, tm, pos, new_val);
        else update(st, v*2 + 1, tm+1, tr, pos, new_val);
        st[v] = func(st[v*2], st[v*2 + 1]);
    }
}

void solve() {
    
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}