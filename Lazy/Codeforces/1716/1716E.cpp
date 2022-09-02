#include <bits/stdc++.h>
using namespace std;
#define int long long

struct S {
    int pref, suff, sum, ans;
};

const int INF = (int)1E18;
const S ID = {0, 0, 0, 0};

void pull(S& a, S&b, S& c) {
    // compute a from b, c
    a.pref = max(b.pref, b.sum + c.pref);
    a.suff = max(c.suff, c.sum + b.suff);
    a.sum = b.sum + c.sum;
    a.ans = max({b.ans, c.ans, b.suff + c.pref});
}

S make(int val) {
    if(val >= 0) return S{val, val, val, val};
    return S{0, 0, val, 0};
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    int m = 1<<n;
    vector <int> v(m);
    for(int i = 0; i < (m); i++) {
        cin >> v[i];
    }
    vector<vector<S>> st(m);
    st[0].resize(m<<1);
    for(int i = m*2 - 1; i > 0; i--) {
        if(i >= m) st[0][i] = make(v[i - m]);
        else pull(st[0][i], st[0][i<<1], st[0][i<<1|1]);
    }
    for(int mask = 1; mask < m; mask++) {
            
    }
    
    return 0;
}