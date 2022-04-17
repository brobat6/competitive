#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector <int> a(n);
    int l = 0;
    int r = n - 1;
    bool start = false;
    for(int i = n - 1; i >= 0; i--) {
        if(start) {
            a[l++] = v[i];
        } else {
            a[r--] = v[i];
        }
        if(v[i] == 0) {
            start = !start;
        }
    }
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    
    return 0;
}