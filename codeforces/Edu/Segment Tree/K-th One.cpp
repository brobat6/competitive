#include <iostream>
using namespace std;
#define MAXN 100100
#define forn(i, n) for(int i=0; i<n; i++) 

int n, m;
int arr[MAXN];
int st[4*MAXN];
int t1, t2;

void build(int v, int tl, int tr) {
    if(tl==tr) st[v] = arr[tl];
    else {
        int tm = (tl + tr)/2;
        build(v*2, tl, tm);
        build(v*2 + 1, tm + 1, tr);
        st[v] = st[v*2] + st[v*2 + 1]; 
    }
}

int query(int v, int tl, int tr, int k) {
    // Find the kth one in this segment.
    if(tl==tr) return tl;
    // sum > k always.
    int tm = (tl + tr)/2;
    if(st[v*2]<=k) return query(v*2+1, tm+1, tr, k - st[v*2]);
    else return query(v*2, tl, tm, k);
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
    // forn(i, 4*n) printf("st[%d] = %d\n", i, st[i]);
    forn(i, m) {
        cin >> t1 >> t2;
        if(t1==1) {
            if(arr[t2]==1) {
                update(1, 0, n-1, t2, 0);
                arr[t2] = 0;
            }
            else {
                update(1, 0, n-1, t2, 1);
                arr[t2] = 1;
            }
        }
        else {
            cout << query(1, 0, n-1, t2) << endl;
        }
    }
}