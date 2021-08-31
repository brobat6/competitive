#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void func(int n, int m, int k, int a, int b, int c, int d) {
    int hor = d - b;
    int ver = c - a;
    int ans = 0;
    int t1 = hor * ((ver+1)/k + ((ver+1)%k ? 1 : 0)) + ver * (hor + 1);
    int t2 = ver * ((hor+1)/k + ((hor+1)%k ? 1 : 0)) + hor * (ver + 1);
    ans += min(t1, t2);
    // cerr << ans << endl;
    int top{0}, bot{0}, right{0}, left{0};
    if(a==1) top = 1;
    if(c==n) bot = 1;
    if(b==1) left = 1;
    if(d==m) right = 1;
    int chk = top + bot + left + right;
    // cerr << chk << endl;
    if(chk > 0) {
        if(a != 1) ans += ((hor+1)/k + ((hor+1)%k ? 1 : 0));
        if(c != n) ans += ((hor+1)/k + ((hor+1)%k ? 1 : 0));
        if(b != 1) ans += ((ver+1)/k + ((ver+1)%k ? 1 : 0));
        if(d != m) ans += ((ver+1)/k + ((ver+1)%k ? 1 : 0));
        cout << ans << endl;
        return;
    }
    int min_ver = min(a - 1, n - c) + ver + 1;
    int min_hor = min(b - 1, m - d) + hor + 1;
    int t3 = 2*((ver+1)/k + ((ver+1)%k ? 1 : 0)) + ((hor+1)/k + ((hor+1)%k ? 1 : 0)) + ((min_hor)/k + ((min_hor)%k ? 1 : 0));
    int t4 = ((ver+1)/k + ((ver+1)%k ? 1 : 0)) + 2*((hor+1)/k + ((hor+1)%k ? 1 : 0)) + ((min_ver)/k + ((min_ver)%k ? 1 : 0));
    ans += min(t3, t4);
    // cerr << t3 << " " << t4 << endl;
    cout << ans << endl;
}

void solve() {
    int n, m, k;
    int a, b, c, d;
    cin >> n >> m >> k >> a >> b >> c >> d;
    if(k!=1) {
        func(n, m, k, a, b, c, d);
        return;
    }
    int hor = d - b;
    int ver = c - a;
    int ans = 0;
    if(a != 1) ans += (hor + 1);
    if(c != n) ans += (hor + 1);
    if(b != 1) ans += (ver + 1);
    if(d != m) ans += (ver + 1);
    ans += hor * (ver + 1);
    ans += ver * (hor + 1);
    ans += min({a - 1, n - c, b - 1, m - d});
    cout << ans << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int T = 1;
    cin >> T;
    forn(I, 1, T+1) {
        cout << "Case #" << I << ": ";
        solve();
    }

    return 0;
}