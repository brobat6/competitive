#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, r, c, sx, sy;
    cin >> n >> r >> c >> sx >> sy;
    --sx; --sy;
    vector<set<int>> x(r), y(c);
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            x[i].insert(j);
            y[j].insert(i);
        }
    }
    x[sx].erase(sy);
    y[sy].erase(sx);
    int curr_x = sx;
    int curr_y = sy;
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        int next_x = curr_x, next_y = curr_y;
        if(c == 'E') {
            next_y = *x[curr_x].lower_bound(curr_y);
        } else if(c == 'W') {
            next_y = *(--x[curr_x].lower_bound(curr_y));
        } else if(c == 'N') {
            next_x = *(--y[curr_y].lower_bound(curr_x));
        } else {
            next_x = *y[curr_y].lower_bound(curr_x);
        }
        x[next_x].erase(next_y);
        y[next_y].erase(next_x);
        curr_x = next_x;
        curr_y = next_y;
    }
    cout << curr_x + 1 << ' ' << curr_y + 1 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        cout << "Case #" << I << ": ";
        solve();
    }
    
    return 0;
}