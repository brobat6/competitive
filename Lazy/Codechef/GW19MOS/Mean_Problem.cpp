#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> v(n);
        queue <int> q;
        int x = 0;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            q.push(v[i]);
            x += v[i];
        }
        for(int i = 0; i < 1000005; i++) {
            v.push_back(x / n);
            x -= q.front();
            q.pop();
            x += v.back();
            q.push(v.back());
        }
        int k;
        cin >> k;
        for(int i = 0; i < k; i++) {
            int y;
            cin >> y;
            --y;
            if(y >= (int)v.size()) {
                cout << v.back() << '\n';
            } else {
                cout << v[y] << '\n';
            }
        }
    }
    
    return 0;
}