#include <bits/stdc++.h>
using namespace std;
#define int long long

vector <int> solve(vector <int>& v) {
    int n = v.size();
    vector <int> ans(1<<n, 0);
    for(int i = 1; i < (1<<n); i++) {
        int x = __builtin_popcount(i);
        int store = -1;
        for(int j = 0; j < n; j++) {
            if((i >> j) & 1) {
                store = j;
                break;
            }
        }
        if(x == 1) {
            ans[i] = v[store];
            continue;
        }
        int prev = ans[i - (1<<store)];
        ans[i] = prev + v[store];
    }
    vector <int> w;
    for(auto i : ans) w.push_back(i);
    return w;
} 

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        vector <int> temp(n);
        for(int i = 0; i < n; i++) {
            cin >> temp[i];
        }
        vector <int> v;
        for(int i = 0; i < n; i++) {
            int x = 0;
            for(int j = i*(i+1)/2; j < (i+1)*(i+2)/2; j++) {
                if(j >= n) {
                    x = -1;
                    break;
                } 
                x += temp[j];
            }
            if(x >= 0) v.push_back(x);
        }
        // for(auto i : v) cout << i << " ";
        n = v.size();
        temp.clear();
        for(int i = 0; i < n/2; i++) {
            temp.push_back(v[i]);
        }
        auto A = solve(temp);
        temp.clear();
        for(int i = n/2; i < n; i++) {
            temp.push_back(v[i]);
        }
        auto B = solve(temp);
        // for(auto i : A) cout << i << " "; cout << '\n';
        // for(auto i : B) cout << i << " "; cout << '\n';
        sort(B.begin(), B.end());
        int ans = 0;
        for(auto i : A) {
            if(i > x) continue;
            int b = upper_bound(B.begin(), B.end(), x - i) - B.begin() - 1;
            if(b >= 0 && b < (int)B.size()) {
                ans = max(ans, i + B[b]);
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}