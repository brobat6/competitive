#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> t;
vector<vector<int>> a;
int m;

void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
    if (ly == ry) {
        if (lx == rx)
            t[vx][vy] = a[lx][ly];
        else
            t[vx][vy] = t[vx*2][vy] ^ t[vx*2+1][vy];
    } else {
        int my = (ly + ry) / 2;
        build_y(vx, lx, rx, vy*2, ly, my);
        build_y(vx, lx, rx, vy*2+1, my+1, ry);
        t[vx][vy] = t[vx][vy*2] ^ t[vx][vy*2+1];
    }
}

void build_x(int vx, int lx, int rx) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        build_x(vx*2, lx, mx);
        build_x(vx*2+1, mx+1, rx);
    }
    build_y(vx, lx, rx, 1, 0, m-1);
}

int sum_y(int vx, int vy, int tly, int try_, int ly, int ry) {
    if (ly > ry) 
        return 0;
    if (ly == tly && try_ == ry)
        return t[vx][vy];
    int tmy = (tly + try_) / 2;
    return sum_y(vx, vy*2, tly, tmy, ly, min(ry, tmy))
         ^ sum_y(vx, vy*2+1, tmy+1, try_, max(ly, tmy+1), ry);
}

int sum_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if (lx > rx)
        return 0;
    if (lx == tlx && trx == rx)
        return sum_y(vx, 1, 0, m-1, ly, ry);
    int tmx = (tlx + trx) / 2;
    return sum_x(vx*2, tlx, tmx, lx, min(rx, tmx), ly, ry)
         ^ sum_x(vx*2+1, tmx+1, trx, max(lx, tmx+1), rx, ly, ry);
}

void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val) {
    if (ly == ry) {
        if (lx == rx)
            t[vx][vy] = new_val;
        else
            t[vx][vy] = t[vx*2][vy] ^ t[vx*2+1][vy];
    } else {
        int my = (ly + ry) / 2;
        if (y <= my)
            update_y(vx, lx, rx, vy*2, ly, my, x, y, new_val);
        else
            update_y(vx, lx, rx, vy*2+1, my+1, ry, x, y, new_val);
        t[vx][vy] = t[vx][vy*2] ^ t[vx][vy*2+1];
    }
}

void update_x(int vx, int lx, int rx, int x, int y, int new_val) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        if (x <= mx)
            update_x(vx*2, lx, mx, x, y, new_val);
        else
            update_x(vx*2+1, mx+1, rx, x, y, new_val);
    }
    update_y(vx, lx, rx, 1, 0, m-1, x, y, new_val);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, l, g;
    cin >> n >> l >> g;
    // wedth l and length n/l;
    int x = n/l + 1;
    int y = l;
    m = y;
    a.resize(x);
    for(int i = 0; i < x; i++) {
        a[i].resize(y, 0);
    }
    t.resize(4*x);
    for(int i = 0; i < 4*x; i++) {
        t[i].resize(4*y, 0);
    }
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a[i / l][i % l] = temp;
    }
    build_x(1, 0, x - 1);

    for(int i = 0; i < g; i++) {
        string s;
        cin >> s;
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        if(s == "start") {
            int ax = a/l;
            int ay = a%l;
            int bx = min(ax + c - 1, x - 1);
            int by = ay + b - 1;
            cout << sum_x(1, 0, x - 1, ax, bx, ay, by) << '\n';
        } else {
            int ax = a/l;
            int ay = a%l;
            int curr = sum_x(1, 0, x - 1, ax, ax, ay, ay);
            int temp = (curr ^ b ^ c) % 256;
            update_x(1, 0, x - 1, ax, ay, temp);
        }
    }

    
    return 0;
}