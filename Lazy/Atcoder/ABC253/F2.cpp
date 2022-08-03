#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 200100;
int ft[N];

void update(int i, int n, int x) {
    while(i < n) {
        ft[i] += x;
        i |= i + 1;
    }
}

int query(int i) {
    int x = 0;
    while(i >= 0) {
        x += ft[i];
        i &= i + 1;
        i--;
    }
    return x;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    memset(ft, 0, sizeof(ft));
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> qq(q, vector<int>(4));
    for(int i = 0; i < q; i++) {
        cin >> qq[i][0] >> qq[i][1] >> qq[i][2];
        --qq[i][1];
        if(qq[i][0] != 2) {
            --qq[i][2];
        }
        if(qq[i][0] == 1) {
            cin >> qq[i][3];
        }
    }
    reverse(qq.begin(), qq.end());
    vector <int> ans(q, -1);
    map<int, vector<int>> p;
    for(int i = 0; i < q; i++) {
        if(qq[i][0] == 1) {
            update(qq[i][1], m + 1, qq[i][3]);
            update(qq[i][2] + 1, m + 1, -qq[i][3]);
        } else if(qq[i][0] == 2) {
            for(auto j : p[qq[i][1]]) {
                ans[j] = qq[i][2] + (ans[j] - query(qq[i][2]));
            }
            p[qq[i][1]].clear();
        } else {
            ans[i] = query(qq[i][2]);
            p[qq[i][1]].push_back(i);
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto i : ans) if(i != -1) cout << i << '\n';
    
    return 0;
}