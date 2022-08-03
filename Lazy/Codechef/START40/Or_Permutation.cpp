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
        vector <int> a(n), b(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        vector <int> c(30, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 30; j++) {
                c[j] += (b[i]>>j) & 1;
            }
        }
        int x = 0;
        for(int j = 0; j < 30; j++) {
            if(c[j] == n) {
                x += (1<<j);
            }
        }
        for(int i = 0; i < n; i++) {
            a[i] = a[i] | x;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        bool pos = true;
        for(int i = 0; i < n; i++) {
            if(a[i] != b[i]) pos = false;
        }
        cout << (pos ? x : -1) << '\n';
    }
    
    return 0;
}