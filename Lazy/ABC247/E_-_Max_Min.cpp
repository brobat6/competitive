#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, x, y;
    cin >> n >> x >> y;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector <int> xpos, ypos;
    for(int i = 0; i < n; i++) {
        if(v[i] == x) xpos.push_back(i);
        if(v[i] == y) ypos.push_back(i);
    }
    xpos.push_back(n);
    ypos.push_back(n);
    vector <int> valid(n); // valid UPTO valid[i] - 1.
    valid[n - 1] = n - 1;
    if(v[n - 1] >= y && v[n - 1] <= x) valid[n - 1] = n;
    for(int i = n - 2; i >= 0; i--) {
        if(v[i] > x || v[i] < y) {
            valid[i] = i;
        } else {
            valid[i] = valid[i + 1];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int start = max(*lower_bound(xpos.begin(), xpos.end(), i), *lower_bound(ypos.begin(), ypos.end(), i));
        int end = valid[i];
        ans += max(0ll, end - start);
    }
    cout << ans;
    
    return 0;
}