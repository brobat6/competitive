#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector <int> v(n);
    int ans = 0;
    int x = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        --v[i];
        if(v[i] == i) x++;
    }
    ans = x*(x - 1)/2;
    x = 0;
    for(int i = 0; i < n; i++) {
        if(v[i] != i) {
            if(v[v[i]] == i) {
                x++;
            }
        }
    }
    cout << ans + (x/2);
    
    return 0;
}