#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define MAXN 200100
#define MOD 1000000007

int n;
int arr[2*MAXN];
int st[8*MAXN];
int ans[MAXN];
int first[MAXN];

void update(int v, int tl, int tr, int pos, int new_val) {
    if(tl==tr) st[v] = new_val;
    else {
        int tm = (tl + tr)/2;
        if(pos <= tm) update(v*2, tl, tm, pos, new_val);
        else update(v*2 + 1, tm+1, tr, pos, new_val);
        st[v] = st[v*2] + st[v*2 + 1];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if(l > r) return 0;
    if(l==tl && r==tr) return st[v];
    int tm = (tl + tr)/2;
    return sum(v*2, tl, tm, l, min(r, tm)) + sum(v*2 + 1, tm + 1, tr, max(l, tm+1), r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // int t; cin >> t; while(t--)
{
    // Code goes here
    cin >> n;
    forn(i, n*2) {
        cin >> arr[i];
        arr[i]--;
    }
    forn(i, n) first[i] = -1;
    forn(i, 2*n) if(first[arr[i]]==-1) first[arr[i]] = i;
    forn(i, 8*n) st[i] = 0;
    forn(i, 2*n) {
        if(i > first[arr[i]]) {
            update(1, 0, 2*n-1, first[arr[i]], 1);
            ans[arr[i]] = sum(1, 0, 2*n-1, first[arr[i]] + 1, i);
        }
    }
    forn(i, n) cout << ans[i] << " ";
}
    return 0;
}
