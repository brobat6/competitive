#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        cout << "Case #" << I << ": ";
        int n;
        cin >> n;
        int sum = 0;
        vector <string> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            sum += (int)v[i].length();
        }
        vector<pair<int, int>> o(n);
        for(int i = 0; i < n; i++) {
            int x = v[i].length();
            o[i] = {v[i][0] - 'A', v[i][x - 1] - 'A'};
        }
        vector<pair<int, int>> adj(26, {-1, -1});
        vector<int> rec(26, -1);
        bool pos = true;
        map<int, vector<int>> s; // same. 
        for(int i = 0; i < n; i++) {
            if(o[i].first == o[i].second) {
                s[o[i].first].push_back(i);
            } else {
                if(adj[o[i].first].first == -1) {
                    adj[o[i].first] = {o[i].second, i};
                } else {
                    pos = false;
                    break;
                }
                if(rec[o[i].second] == -1) {
                    rec[o[i].second] = o[i].first;
                } else {
                    pos = false;
                    break;
                }
            }
        }
        if(!pos) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        vector <int> temp;
        for(int i = 0; i < 26; i++) {
            if(rec[i] == -1) {
                temp.push_back(i); // this is a new component.
            }
        }
        vector <int> order;
        for(auto start: temp) {
            // order.push_back(start);
            // cerr << start << " ";
            int curr = start;
            for(auto j : s[curr]) {
                order.push_back(j);
            }
            while(adj[curr].first != -1) {
                
                order.push_back(adj[curr].second);
                // cout << curr << " " << adj[curr].second << " ";
                curr = adj[curr].first;
                for(auto j : s[curr]) {
                    order.push_back(j);
                    // cout << j << " ";
                }
            }
        }
        string ans;
        for(auto i : order) {
            ans = ans + v[i];
        }
        //just check now
        vector<vector<int>> cd(26);
        int z = ans.length();
        if(z != sum) pos = false;
        for(int i = 0; i < z; i++) {
            cd[ans[i] - 'A'].push_back(i);
        }
        for(int i = 0; i < 26; i++) {
            int z = cd[i].size();
            for(int j = 1; j < z; j++) {
                if(cd[i][j] != cd[i][j - 1] + 1) {
                    pos = false;
                }
            }
        }
        if(!pos) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        cout << ans << '\n';
        // for(int i = 0; i < 26; i++) {
            // cout << adj[i] << " " << rec[i] << '\n';
        // }
        // cout << pos << '\n';
        // cerr << '\n';
    }
    
    return 0;
}