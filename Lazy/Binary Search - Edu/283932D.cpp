#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int m, n;
    cin >> m >> n;
    vector<vector<int>> v(n, vector<int>(3));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> v[i][j];
        }
    }
    int l = 0;
    int r = (int)1E9;
    int ans = 0;
    vector <int> a(n);
    while(l <= r) {
        int m = (l + r)/2;

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt += v[i][1] * (m / (v[i][0] + v[i][2]));
            int rem = m % (v[i][0] + v[i][2]);
            if(rem >= v[i][0]) cnt += v[i][1];
        }
    }
    
    return 0;
}