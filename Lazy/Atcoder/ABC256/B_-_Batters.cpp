#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    int p = 0;
    vector <int> v(4, 0);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[0]++;
        vector <int> nv(4, 0);
        for(int i = 0; i < 4; i++) {
            if(i + x >= 4) {
                p += v[i];
                v[i] = 0;
            } else {
                nv[i + x] = v[i];
            }
        }
        v = nv;
    }
    cout << p;
    
    return 0;
}