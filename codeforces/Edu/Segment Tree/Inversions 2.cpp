#include <iostream>
using namespace std;
#define MAXN 100100
#define forn(i, n) for(int i=0; i<n; i++) 
 
int n;
int arr[MAXN];
int st[4*MAXN];
int ans[MAXN];
int num_ones;

void build(int v, int tl, int tr) {
    if(tl==tr) st[v] = 1;
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
    cin >> n;
    forn(i, n) cin >> arr[i];
    num_ones = n;
    build(1, 0, n-1);
    // Find the (n-k-1)th one.
    for(int i=n-1; i>=0; i--) {
        int temp = query(1, 0, n-1, num_ones-arr[i]-1);
        num_ones--;
        update(1, 0, n-1, temp, 0);
        ans[i] = temp + 1;
    }
    forn(i, n) cout << ans[i] << " ";
}