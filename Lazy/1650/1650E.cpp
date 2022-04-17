#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, d;
        cin >> n >> d;
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector <int> diff(n);
        diff[0] = v[0];
        for(int i = 1; i < n; i++) {
            diff[i] = v[i] - v[i - 1];
        }
        int mn_ind = min_element(diff.begin(), diff.end()) - diff.begin();
        for(int i = mn_ind - 1; i <= mn_ind; i++) {
            if(i < 0) continue;
            vector <int> a = diff;
            a.push_back(a[n - 1]);
            int temp = a[i] + a[i + 1];
            a[i] = temp;
            a[i + 1] = temp;
        }
        // int mn = v[0];
        // int mn_ind = 0;
        // for(int i = 1; i < n; i++) {
        //     if(v[i] - v[i - 1] < mn) {
        //         mn = v[i] - v[i - 1];
        //         mn_ind = i;
        //     }
        // }
        // v.erase(v.begin() + mn_ind);
        // int ans = mn;
        // if(v[n - 2] != d) v.push_back(d);
        // {
        //     int mn = v[0];
        //     int mn_ind = 0;
        //     for(int i = 1; i < n; i++) {
        //         if(v[i] - v[i - 1] < mn) {
        //             mn = v[i] - v[i - 1];
        //             mn_ind = i;
        //         }
        //     } 
        //     ans = max(ans, mn);
        // }
        // int mx = v[0];
        // int mx_ind = 0;
        // v.pop_back();
        // for(int i = 1; i < n - 1; i++) {
        //     if(v[i] - v[i - 1] > mx) {
        //         mx = v[i] - v[i - 1];
        //         mx_ind = i;
        //     }
        // }
        // // insert AT i
        // int pos;
        // if(mx_ind == 0) pos = v[0]/2;
        // else pos = (v[mx_ind] + v[mx_ind - 1])/2;
        // v.insert(v.begin() + mx_ind, pos);
        // {
        //     int mn = v[0];
        //     int mn_ind = 0;
        //     for(int i = 1; i < n; i++) {
        //         if(v[i] - v[i - 1] < mn) {
        //             mn = v[i] - v[i - 1];
        //             mn_ind = i;
        //         }
        //     } 
        //     ans = max(ans, mn);
        // }
        // cout << ans - 1 << '\n';
    }
    
    return 0;
}