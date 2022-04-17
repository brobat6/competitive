#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int solve() {
    int n, m;
    cin >> n >> m;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector <int> pr;
    int sum = accumulate(v.begin(), v.end(), 0ll);
    int f = sum - m;
    for(int i = 1; i * i <= f; i++) {
        if(f % i == 0) {
            if(i * i == f) pr.push_back(i);
            else {
                pr.push_back(i);
                pr.push_back(f/i);
            }
        }
    }
    sort(pr.begin(), pr.end(), greater<int>());
    for(auto i : pr) {
        int needed = 0;
        int surplus = 0;
        bool pos = true;
        for(int j = 0; j < n; j++) {
            needed += (v[j] - i * (v[j] / i));
            if(needed > m) {
                pos = false;
                break;
            }
            surplus += i * (v[j] / i);
        }
        if(pos && needed <= m && (m - needed) % i == 0 && (m - needed) <= surplus) {
            return i;
        }
    }
    return 1;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        cout << solve() << endl;
    }
    
    return 0;
}