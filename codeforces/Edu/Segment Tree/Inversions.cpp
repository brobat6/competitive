#include <iostream>
using namespace std;
#define MAXN 100100
#define forn(i, n) for(int i=0; i<n; i++) 
 
int n, m;
int arr[MAXN];
int st[4*MAXN];
int ans[MAXN];

int sum(int v, int tl, int tr, int l, int r) {
    if(l > r) return 0;
    if(l==tl && r==tr) return st[v];
    int tm = (tl + tr)/2;
    return sum(v*2, tl, tm, l, min(r, tm)) + sum(v*2 + 1, tm + 1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if(tl==tr) st[v] = new_val;
    else {
        int tm = (tl + tr)/2;
        if(pos <= tm) update(v*2, tl, tm, pos, new_val);
        else update(v*2 + 1, tm+1, tr, pos, new_val);
        st[v] = st[v*2] + st[v*2 + 1];
    }
}
 
int main() {
    cin >> n;
    forn(i, n) cin >> arr[i];
    forn(i, 4*n) st[i] = 0;
    forn(i, n) {
        ans[i] = sum(1, 0, n-1, arr[i]-1, n-1);
        update(1, 0, n-1, arr[i]-1, 1);
    }
    forn(i, n) cout << ans[i] << " ";
}