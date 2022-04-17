#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int find_mex(deque <int> &v, int sub) {
    // Return MEX, assuming v is sorted.
    int curr = 0;
    for(auto i : v) {
        if(curr == i - sub) curr++;
        else return curr;
    }
    return (int)v.size();
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        set <int> s;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            s.insert(x);
        }
        deque <int> v;
        for(auto i : s) {
            v.push_back(i);
        }
        int m = v.size();
        int mex = find_mex(v, 0);
        if(mex == 0) {
            cout << v[0] - 1 << endl;
            continue;
        }
        if(mex == 1) {
            cout << -1 << endl;
            continue;
        }
        int cnt = 0;
        vector <int> suff(m, 0);
        for(int i = m - 2; i >= 0; i--) {
            if(v[i] == v[i + 1] - 1) {
                suff[i] = suff[i + 1] + 1;
            }
        }
        for(int i = 0; i < m; i++) {
            // cout << suff[i] << " ";
            if(suff[i] == mex - 2) {
                cnt++;
            }
        }
        cout << cnt - 1 << endl;
    }
    
    return 0;
}