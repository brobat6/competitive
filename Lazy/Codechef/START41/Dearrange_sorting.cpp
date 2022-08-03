#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> v(n);
        vector <int> c;
        vector <int> w;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            if(v[i] == i + 1) c.push_back(i);
            else w.push_back(i);
        }
        if(w.empty()) {
            cout << 0 << '\n';
            continue;
        }
        bool one = true;
        for(int i = 1; i < (int)w.size(); i++) {
            if(w[i] != w[i - 1] + 1) one = false;
        }
        if(one) {
            cout << 1 << '\n';
            cout << (*w.begin()) + 1 << " " << (*w.rbegin()) + 1 << '\n';
            for(int i = 1; i <= n; i++) cout << i << " ";
            cout << '\n';
        } else {
            cout << 2 << '\n';
            cout << 1 << " " << n << '\n';
            vector <int> nv(n, -1);
            {
                vector <int> vis(n, false);
                vector<vector<pair<int, int>>> c(n);
                for(int i = 0; i < n; i++) v[i]--;
                for(int i = 0; i < n; i++) {
                    if(!vis[i]) {
                        c[i].push_back({i, v[i]});
                        int j = v[i];
                        vis[i] = true;
                        while(j != i) {
                            vis[j] = true;
                            c[i].push_back({j, v[j]});
                            j = v[j];
                        }
                    }
                }
                for(int i = 0; i < n; i++) {
                    for(int j = i + 1; j < n; j++) {
                        int x = c[i].size();
                        int y = c[j].size();
                        if(y > x) swap(c[i], c[j]);
                    }
                }
                // sort(c.begin(), c.end(), [&](vector<pair<int, int>> a, vector<pair<int, int>> b) {
                //     return ((int)a.size() > (int)b.size());
                // });
                // for(auto i : c) {
                //     for(auto j : i) cout << j.second + 1 << " ";
                //     cout << '\n';
                // }

                // left shift on largest cycle
                int xx = c[0].size();
                vector<pair<int, int>> nxx = c[0];
                for(int i = 0; i < xx; i++) {
                    nxx[(i - 1 + xx) % xx].second = c[0][i].second;
                    // nxx[(i + 1) % xx].second = c[0][i].second;
                }
                c[0] = nxx;
                for(int i = 0; i < n; i++) {
                    int sz = 0;
                    for(int j = 0; j < n; j++) {
                        if((int)c[j].size() > i) {
                            sz++;
                        }
                    }
                    if(sz == 1) continue;
                    vector<pair<int, int>> nx(sz);
                    for(int j = 0; j < sz; j++) {
                        nx[j].first = c[j][i].first;
                        nx[(j + 1) % sz].second = c[j][i].second;
                    }
                    for(int j = 0; j < sz; j++) {
                        c[j][i] = nx[j];
                    }
                }
                if((int)c[0].size() == 2 && (int)c[1].size() == 1) {
                    swap(c[1][0].second, c[0][1].second);
                }
                for(auto i : c) {
                    for(auto j : i) {
                        nv[j.first] = j.second;
                        cout << j.first + 1 << " " << j.second + 1 << '\n';
                    }
                }
            }
            for(int i = 0; i < n; i++) {
                // assert(nv[i] >= 0);
                // assert(nv[i] != v[i]);
                // assert(nv[i] != i);
                cout << nv[i] + 1 << " ";
            }
            cout << '\n';
            cout << 1 << " " << n << '\n';
            for(int i = 1; i <= n; i++) cout << i << " ";
            cout << '\n';
        }
    }
    
    return 0;
}