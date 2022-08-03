#include <bits/stdc++.h>
using namespace std;
#define int long long

const int M = 30;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> v(M);
    vector <int> reset(M, false);
    for(int i = 0; i < M; i++) {
        v[i] = {(x >> i) & 1, 0};
    }
    for(int i = 0; i < n; i++) {
        int t, a;
        cin >> t >> a;
        for(int j = 0; j < M; j++) {
            int x = (a >> j) & 1;
            if(t == 1) {
                if(x == 0) {
                    v[j] = {0, 0};
                    reset[j] = true;
                }
            } else if(t == 2) {
                if(x == 1) {
                    v[j] = {1, 0};
                    reset[j] = true;
                }
            } else {
                if(x == 1) {
                    v[j].second++;
                }
            }
        }
        int ans = 0;
        for(int j = 0; j < M; j++) {
            ans += (v[j].first ^ (v[j].second % 2))<<j;
            if(!reset[j]) {
                v[j].first ^= (v[j].second % 2);
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}