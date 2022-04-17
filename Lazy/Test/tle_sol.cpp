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
    for(int i = 0; i < n; i++) {
        if(v[i] == 0) {
            reverse(v.begin(), v.begin() + i);
        }
    }
    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    
    return 0;
}