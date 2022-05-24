#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k, p;
    cin >> n >> k >> p;
    --p;
    vector <int> v(n, k);
    vector<vector<int>> h;
    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < n; j++) cout << v[j] << " ";
        cout << '\n';
        h.push_back(v);
        vector <int> w(n, 0);
        for(int i = 0; i < n; i++) {
            if(i == p) {
                w[(i + 1) % n] += v[i];
            } else {
                w[(i + 1) % n] += (v[i] + 1)/2;
                w[(i - 1 + n) % n] += v[i]/2;
            }
        }
        bool done = false;
        for(int j = 0; j <= i; j++) {
            bool e = true;
            for(int k = 0; k < n; k++) {
                if(h[j][k] != w[k]) e = false;
            }
            if(e) {
                cout << i << " equal to " << j << '\n';
                done = true;
                break;
            }
        }
        if(done) break;
        v = w;
    }
    
    return 0;
}