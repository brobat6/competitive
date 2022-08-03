#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector <int> v(2*m + 1, 0);
    for(int i = 0; i < n; i++) {
        int x; cin >> x; 
        v[x] = 1;
    }
    vector<vector<int>> f(2*m + 1);
    for(int i = 0; i <= 2*m; i++) {
        f[i].push_back(i);
    }
    for(int i = 1; i <= 2*m; i++) {
        if(v[i] == 0) continue;
        for(int j = i * 2; j <= 2*m; j += i) {
            if(v[j] == 0) continue;
            f[i].push_back(j);
            f[j].push_back(i);
        }
    }
    // for(int i = 1; i <= 2*m; i++) {
    //     for(auto j : f[i]) cout << j << " ";
    //     cout << '\n';
    // }
    vector <pair<int, int>> sz(2*m + 1);
    for(int i = 0; i <= 2*m; i++) {
        sz[i] = {(int)f[i].size(), i};
    }
    sort(sz.begin(), sz.end(), [&](pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    });
    vector <int> ms(2*m + 1, 0);
    for(int i = 0; i <= 2*m; i++) {
        int x = sz[i].second;
        // cout << x << '\n';
        if(v[x] == 0) continue;
        bool pos = true;
        for(auto j : f[x]) {
            if(ms[j] == 1) {
                pos = false;
                break;
            }
        }
        if(pos) {
            ms[x] = 1;
        }
    }
    // for(int i = 0; i <= 2*m; i++) {
    //     if(ms[i] == 1) cout << i << " ";
    // }
    set <int> good;
    for(int i = 0; i <= 2*m; i++) {
        if(ms[i] == 1) good.insert(i);
    }
    if((int)good.size() < m) {
        for(int i = 0; i < n; i++) {
            cout << "No\n";
        }
        return 0;
    }
    vector <int> ans(2*m + 1, -1);
    for(auto i : good) {
        ans[i] = 1;
    }
    for(int i = 0; i <= 2*m; i++) {
        vector <int> rem;
        vector <int> add;
        if(v[i] == 1 && (good.find(i) == good.end())) {
            // figure out if i can become part of a good set or not.
            // first, remove all values in f[i] from good.
            for(auto j : f[i]) {
                if(good.find(j) != good.end()) {
                    good.erase(j);
                    rem.push_back(j);
                }
            }
            // now add i to good
            good.insert(i);
            add.push_back(i);
            // now add all possible f[] from list of rem.
            for(auto j : rem) {
                for(auto k : f[j]) {
                    // can I add k to the list??
                    bool pos = true;
                    for(auto z : f[k]) {
                        if(good.find(z) != good.end()) {
                            pos = false;
                            break;
                        }
                    }
                    if(pos) {
                        good.insert(k);
                        add.push_back(k);
                    }
                }
            } 
            if((int)good.size() < m) {
                ans[i] = 0;
            } else {
                ans[i] = 1;
            }
            for(auto i : add) good.erase(i);
            for(auto i : rem) good.insert(i);
        }
    }
    for(int i = 0; i <= 2*m; i++) {
        if(ans[i] == 0) cout << "No\n";
        if(ans[i] == 1) cout << "Yes\n";
    }
    return 0;
}