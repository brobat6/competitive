#include <bits/stdc++.h>
using namespace std;
#define int long long

const double EPS = 1E-6;

void solve() {
    int r;
    cin >> r;
    map<pair<int, int>, bool> f;
    map<pair<int, int>, bool> g;
    for(int i = -r; i <= r; i++) {
        for(int j = -r; j <= r; j++) {
            f[{i, j}] = g[{i, j}] = false;
        }
    }
    for(int i = -r; i <= r; i++) {
        for(int j = -r; j <= r; j++) {
            int x = round(sqrt((i * i + j * j) * 1.0) - EPS);
            if(x <= r) {
                f[{i, j}] = true;
            }
        }
    }
    for(int a = 0; a <= r; a++) {
        for(int b = -a; b <= a; b++) {
            int c = round(sqrt((a * a - b * b) * 1.0) - EPS);

            g[{b, c}] = g[{b, -c}] = g[{c, b}] = g[{-c, b}] = true;
        }
    }
    cout << '\n';
    for(int i = -r; i <= r; i++) {
        for(int j = -r; j <= r; j++) {
            if(f[{i, j}]) cout << 1 << " ";
            else cout << 0 << " ";
        }
        cout << '\n';
    }
    cout << '\n';
    for(int i = -r; i <= r; i++) {
        for(int j = -r; j <= r; j++) {
            if(g[{i, j}]) cout << 1 << " ";
            else cout << 0 << " ";
        }
        cout << '\n';
    }
    cout << '\n';

    int cnt = 0;
    for(int i = -r; i <= r; i++) {
        for(int j = -r; j <= r; j++) {
            if(f[{i, j}] != g[{i, j}]) cnt++;
        }
    }
    cout << cnt << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    
    return 0;
}