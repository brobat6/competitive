#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector <pair<int, int>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    vector <pair<int, int>> ans(1, v[0]);
    int curr = 0;
    for(int i = 1; i < n; i++) {
        if(v[i].first <= ans[curr].second) {
            ans[curr].second = max(ans[curr].second, v[i].second);
        } else {
            curr++;
            ans.push_back(v[i]);
        }
    }
    for(auto i : ans) cout << i.first << " " << i.second << '\n';
    
    return 0;
}