#include <bits/stdc++.h>
using namespace std;
#define int long long

pair<vector<int>, vector<int>> find_subarrays(vector<int> &v, int n) {
    vector <int> a, b;
    int f = 0;
    a.push_back(v[0]);
    int nx = -1;
    for(int i = 1; i < n; i++) {
        if(v[i] > v[i - 1]) {
            a.push_back(v[i]);
        } else {
            nx = i;
            break;
        }
    }
    if(nx != -1) {
        b.push_back(v[nx]);
        for(int i = nx + 1; i < n; i++) {
            if(v[i] > v[i - 1]) {
                b.push_back(v[i]);
            } else {
                break;
            }
        }
    }
    return {a, b};
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            --v[i];
        }
        vector <pair<int, int>> ops;
        for(int i = 0; i < n; i++) {
            auto [a, b] = find_subarrays(v, n);
            // cout << "SUBARRAYS!";
            // for(auto i : a) cout << i + 1 << " "; cout << '\n';
            // for(auto i : b) cout << i + 1 << " "; cout << '\n';
            int nn = a.size();
            int m = b.size();
            if(m == 0) break;
            vector<pair<int, int>> c;
            for(int i = 0; i < nn; i++) {
                c.push_back({i, 0});
            }
            for(int i = 0; i < m; i++) {
                c.push_back({nn + i, 1});
            }
            sort(c.begin(), c.end(), [&](pair<int, int> a, pair<int, int> b) {
                return v[a.first] < v[b.first];
            });
            // cout << "COMBO!";
            // for(auto i : c) cout << i.first << "," << i.second << " ";
            // cout << "OPS!";
            for(int j = 0; j < m; j++) {
                for(int i = 0; i < nn + m - 1; i++) {
                    if(c[i].second == 1 && c[i + 1].second == 0) {
                        // swap!
                        ops.push_back({c[i].first, c[i + 1].first});
                        // cout << "SWAP - " << c[i].first << " " << c[i + 1].first << '\n';
                        // c[i + 1].second = 1;
                        // c[i].second = 0;
                        swap(c[i], c[i + 1]);
                        swap(v[c[i].first], v[c[i + 1].first]);
                    }
                }
            }
        }
        int k = ops.size();
        assert(k <= n*n);
        cout << k << '\n';
        for(auto op : ops) {
            if(op.first > op.second) swap(op.first, op.second);
            cout << op.first + 1 << " " << op.second + 1 << '\n';
        }
    }
    
    return 0;
}