#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define MAXN 200100
#define MOD 1000000007

ll n, m;
ll st[4*MAXN];
ll t1, t2, t3, t4;
 
ll sum(ll v, ll tl, ll tr, ll l, ll r) {
    if(l > r) return 0;
    if(l==tl && r==tr) return st[v];
    ll tm = (tl + tr)/2;
    return sum(v*2, tl, tm, l, min(r, tm)) + sum(v*2 + 1, tm + 1, tr, max(l, tm+1), r);
}
 
void update(ll v, ll tl, ll tr, ll pos, ll new_val) {
    if(tl==tr) st[v] += new_val;
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
    // freopen("input.txt","r",stdin);
    // ll t; cin >> t; while(t--)
{
    // Code goes here
    cin >> n >> m;
    forn(i, 4*(n+1)) st[i] = 0;
    forn(i, m) {
        cin >> t1;
        if(t1==1) {
            cin >> t2 >> t3 >> t4;
            update(1, 0, n, t2, t4);
            update(1, 0, n, t3, -t4);
        }
        else {
            cin >> t2;
            cout << sum(1, 0, n, 0, t2) << endl;
        }
    }
}
    return 0;
}
