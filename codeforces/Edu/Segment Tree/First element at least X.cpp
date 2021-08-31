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
        st[v] = max(st[v*2], st[v*2 + 1]);
    }
}
 
// int find_max(int v, int tl, int tr, int l, int r) {
//     if(l > r) return 0;
//     if(l==tl && r==tr) return st[v];
//     int tm = (tl + tr)/2;
//     return min(find_max(v*2, tl, tm, l, min(r, tm)), find_max(v*2 + 1, tm + 1, tr, max(l, tm+1), r));
// }

int query(int v, int tl, int tr, int x) {
    if(st[v] < x) return -1;
    if(tl==tr) return tl;
    int tm = (tl + tr)/2;
    if(st[v*2] < x) return query(v*2 + 1, tm + 1, tr, x);
    else return query(v*2, tl, tm, x);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if(tl==tr) st[v] = new_val;
    else {
        int tm = (tl + tr)/2;
        if(pos <= tm) update(v*2, tl, tm, pos, new_val);
        else update(v*2 + 1, tm+1, tr, pos, new_val);
        st[v] = max(st[v*2], st[v*2 + 1]);
    }
}

bool check(int pos, int x) {
    return arr[pos] >= x;
}
 
int main() {
    cin >> n >> m;
    forn(i, n) cin >> arr[i];
    build(1, 0, n-1);
    forn(i, m) {
        cin >> t1;
        if(t1==1) {
            cin >> t1 >> t2;
            update(1, 0, n-1, t1, t2);
        }
        else {
            cin >> t2;
            cout << query(1, 0, n-1, t2) << endl;
        }
    }
}