#include <iostream>
using namespace std;

int arr[]{1,3,-2,8,-7};
int n = 5;
int st[20]; //4 * MAXN

void build(int v, int tl, int tr) {
    if(tl==tr) st[v] = arr[tl];
    else {
        int tm = (tl + tr)/2;
        build(v*2, tl, tm);
        build(v*2 + 1, tm + 1, tr);
        st[v] = st[v*2] + st[v*2 + 1]; 
    }
}

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
    build(1, 0, 4);
    // for(int i=0; i<20; i++) printf("st[%d] = %d\n", i, st[i]);
    cout << sum(1, 0, 4, 0, 3);
    return 0;
}