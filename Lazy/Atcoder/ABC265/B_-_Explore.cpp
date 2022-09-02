#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, t;
    cin >> n >> m >> t;
    vector <int> a(n - 1);
    for(int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }
    vector <int> bonus(n, 0);
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        --x;
        bonus[x] = y;
    }
    int curr = t;
    for(int i = 0; i < n - 1; i++) {
        curr -= a[i];
        if(curr <= 0) {
            cout << "No";
            return 0;
        }
        curr += bonus[i + 1];
    }
    cout << "Yes";
    
    return 0;
}