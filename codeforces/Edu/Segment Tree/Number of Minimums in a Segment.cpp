#include <iostream>
#include <utility>
using namespace std;
#define MAXN 100100
#define forn(i, n) for(int i=0; i<n; i++) 

int n, m;
int arr[MAXN];
pair<int, int> st[4*MAXN];
int t1, t2, t3;

void build(int v, int tl, int tr) {
    if(tl==tr) st[v] = {arr[tl], 1};
    else {
        int tm = (tl + tr)/2;
        build(v*2, tl, tm);
        build(v*2 + 1, tm + 1, tr);
        if(st[v*2].first > st[v*2 + 1].first) st[v] = st[v*2 + 1];
        else if(st[v*2].first < st[v*2 + 1].first) st[v] = st[v*2];
        else st[v] = {st[v*2].first, st[v*2].second + st[v*2 + 1].second};
    }
}

pair<int, int> find_min(int v, int tl, int tr, int l, int r) {
    if(l > r) return {1000000001, 0};
    if(l==tl && r==tr) return st[v];
    int tm = (tl + tr)/2;
    auto x = find_min(v*2, tl, tm, l, min(r, tm));
    auto y = find_min(v*2 + 1, tm + 1, tr, max(l, tm+1), r);
    if(x.first > y.first) return y;
    else if(x.first < y.first) return x;
    else return {x.first, x.second + y.second};
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if(tl==tr) st[v] = {new_val, 1};
    else {
        int tm = (tl + tr)/2;
        if(pos <= tm) update(v*2, tl, tm, pos, new_val);
        else update(v*2 + 1, tm+1, tr, pos, new_val);
        if(st[v*2].first > st[v*2 + 1].first) st[v] = st[v*2 + 1];
        else if(st[v*2].first < st[v*2 + 1].first) st[v] = st[v*2];
        else st[v] = {st[v*2].first, st[v*2].second + st[v*2 + 1].second};
    }
}

int main() {
    cin >> n >> m;
    forn(i, n) cin >> arr[i];
    build(1, 0, n-1);
    forn(i, m) {
        cin >> t1 >> t2 >> t3;
        if(t1==1) update(1, 0, n-1, t2, t3);
        if(t1==2) {
            auto x = find_min(1, 0, n-1, t2, t3 - 1);
            cout << x.first << " " << x.second << endl;
        }
    }
}