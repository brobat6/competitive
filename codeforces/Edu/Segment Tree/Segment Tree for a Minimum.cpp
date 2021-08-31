#include <iostream>
using namespace std;
#define MAXN 100100
#define forn(i, n) for(int i=0; i<n; i++) 

int n, m;
int arr[MAXN];
int st[4*MAXN];
int t1, t2, t3;

void build(int v, int tl, int tr) {
    if(tl==tr) st[v] = arr[tl];
    else {
        int tm = (tl + tr)/2;
        build(v*2, tl, tm);
        build(v*2 + 1, tm + 1, tr);
        st[v] = min(st[v*2], st[v*2 + 1]);
    }
}

int find_min(int v, int tl, int tr, int l, int r) {
    if(l > r) return 1000000000;
    if(l==tl && r==tr) return st[v];
    int tm = (tl + tr)/2;
    return min(find_min(v*2, tl, tm, l, min(r, tm)), find_min(v*2 + 1, tm + 1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if(tl==tr) st[v] = new_val;
    else {
        int tm = (tl + tr)/2;
        if(pos <= tm) update(v*2, tl, tm, pos, new_val);
        else update(v*2 + 1, tm+1, tr, pos, new_val);
        st[v] = min(st[v*2], st[v*2 + 1]);
    }
}

int main() {
    cin >> n >> m;
    forn(i, n) cin >> arr[i];
    build(1, 0, n-1);
    forn(i, m) {
        cin >> t1 >> t2 >> t3;
        if(t1==1) update(1, 0, n-1, t2, t3);
        if(t1==2) cout << find_min(1, 0, n-1, t2, t3 - 1) << endl;
    }
}