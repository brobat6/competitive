#include <iostream>
using namespace std;
#define forn(i, n) for(long long i=0; i<n; i++)
#define MAXN 100100

long long lft[4*MAXN];
long long rght[4*MAXN];
long long mid[4*MAXN];
long long tot[4*MAXN];
long long n, m;
long long arr[MAXN];

void make_st(long long v, long long tl, long long val) {
    rght[v] = val;
    lft[v] = val;
    mid[v] = val;
    tot[v] = val;
    // func(v);
}

void build_st(long long v, long long tl, long long tm, long long tr) {
    tot[v] = tot[2*v] + tot[2*v + 1];
    lft[v] = max(lft[2*v], tot[2*v]);
    lft[v] = max(lft[v], tot[2*v] + lft[2*v + 1]);
    rght[v] = max(rght[2*v+1], tot[2*v+1]);
    rght[v] = max(rght[v], tot[2*v+1] + rght[2*v]);
    mid[v] = max(tot[v], lft[v]);
    mid[v] = max(mid[v], rght[v]);
    mid[v] = max(mid[v], rght[2*v] + lft[2*v + 1]);
    mid[v] = max(mid[v], lft[2*v + 1]);
    mid[v] = max(mid[v], rght[2*v]);
    mid[v] = max(mid[v], mid[2*v]);
    mid[v] = max(mid[v], mid[2*v + 1]);
}

void build(long long v, long long tl, long long tr) {
    if(tl==tr) make_st(v, tl, arr[tl]);
    else {
        long long tm = (tl + tr)/2;
        build(v*2, tl, tm);
        build(v*2 + 1, tm + 1, tr);
        build_st(v, tl, tm, tr);
    }
}

void update(long long v, long long tl, long long tr, long long pos, long long new_val) {
    if(tl==tr) make_st(v, pos, new_val);
    else {
        long long tm = (tl + tr)/2;
        if(pos <= tm) update(v*2, tl, tm, pos, new_val);
        else update(v*2 + 1, tm+1, tr, pos, new_val);
        build_st(v, tl, tm, tr);
    }
}

int main() {
    cin >> n >> m;
    forn(i, n) cin >> arr[i];
    build(1, 0, n-1);
    cout << max(mid[1], 0ll) << endl;
    long long t1, t2;
    forn(i, m) {
        cin >> t1 >> t2;
        update(1, 0, n-1, t1, t2);
        cout << max(mid[1], 0ll) << endl;
    }
}