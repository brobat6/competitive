#include <bits/stdc++.h>
using namespace std;

#define MAXN 200100

int arr[MAXN];
int st[4*MAXN];

int func(int a, int b) {
    // return a + b; // Segment tree for the sum
    // return min(a, b); // Segment tree for the minimum
}

void build(int v, int tl, int tr) {
    if(tl==tr) st[v] = arr[tl]; // Assign value here.
    else {
        int tm = (tl + tr)/2;
        build(v*2, tl, tm);
        build(v*2 + 1, tm + 1, tr);
        st[v] = func(st[v*2], st[v*2 + 1]);
    }
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if(tl==tr) st[v] = new_val; // Assign value here.
    else {
        int tm = (tl + tr)/2;
        if(pos <= tm) update(v*2, tl, tm, pos, new_val);
        else update(v*2 + 1, tm+1, tr, pos, new_val);
        st[v] = func(st[v*2], st[v*2 + 1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if(l > r) return 0;
    if(l==tl && r==tr) return st[v];
    int tm = (tl + tr)/2;
    return func(query(v*2, tl, tm, l, min(r, tm)), query(v*2 + 1, tm + 1, tr, max(l, tm+1), r));
}