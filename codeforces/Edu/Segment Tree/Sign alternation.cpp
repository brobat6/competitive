#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define MAXN 100100
#define MOD 1000000007

ll n, m;
long long arr[MAXN];
long long st[4*MAXN];
long long t1, t2, t3;

void build(ll v, ll tl, ll tr) {
    if(tl==tr) st[v] = arr[tl];
    else {
        ll tm = (tl + tr)/2;
        build(v*2, tl, tm);
        build(v*2 + 1, tm + 1, tr);
        st[v] = st[v*2] + st[v*2 + 1]; 
    }
}

long long sum(ll v, ll tl, ll tr, ll l, ll r) {
    if(l > r) return 0;
    if(l==tl && r==tr) return st[v];
    ll tm = (tl + tr)/2;
    return sum(v*2, tl, tm, l, min(r, tm)) + sum(v*2 + 1, tm + 1, tr, max(l, tm+1), r);
}

void update(ll v, ll tl, ll tr, ll pos, ll new_val) {
    if(tl==tr) st[v] = new_val;
    else {
        ll tm = (tl + tr)/2;
        if(pos <= tm) update(v*2, tl, tm, pos, new_val);
        else update(v*2 + 1, tm+1, tr, pos, new_val);
        st[v] = st[v*2] + st[v*2 + 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    cin >> n;
    forn(i, n) {
        cin >> arr[i];
        if(i%2) arr[i] *= -1;
    }
    build(1, 0, n-1);
    cin >> m;
    forn(i, m) {
        cin >> t1 >> t2 >> t3;
        if(t1) {
            if(t2%2) cout << sum(1, 0, n-1, t2 - 1, t3 - 1) << endl;
            else cout << -sum(1, 0, n-1, t2 - 1, t3 - 1) << endl;
            
        }
        else {
            if(t2%2) update(1, 0, n-1, t2 - 1, t3);
            else update(1, 0, n-1, t2 - 1, -t3);
        }
    }
    return 0;
}