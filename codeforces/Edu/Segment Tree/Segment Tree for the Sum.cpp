#include <iostream>
using namespace std;
#define MAXN 100100
#define forn(i, n) for(int i=0; i<n; i++) 

int n, m;
long long arr[MAXN];
long long st[4*MAXN];
long long t1, t2, t3;

void build(int v, int tl, int tr) {
    if(tl==tr) st[v] = arr[tl];
    else {
        int tm = (tl + tr)/2;
        build(v*2, tl, tm);
        build(v*2 + 1, tm + 1, tr);
        st[v] = st[v*2] + st[v*2 + 1]; 
    }
}

long long sum(int v, int tl, int tr, int l, int r) {
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
    cin >> n >> m;
    forn(i, n) cin >> arr[i];
    build(1, 0, n-1);
    forn(i, m) {
        cin >> t1 >> t2 >> t3;
        if(t1==1) update(1, 0, n-1, t2, t3);
        if(t1==2) cout << sum(1, 0, n-1, t2, t3 - 1) << endl;
    }
}