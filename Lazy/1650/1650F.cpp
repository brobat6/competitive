#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector <int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<vector<vector<int>>> v(n); // v[task_no] = {time, completion, task_index};
        vector<vector<int>> tasks;
        for(int i = 0; i < m; i++) {
            vector <int> w(3);
            int e; cin >> e; --e;
            cin >> w[0] >> w[1];
            w[2] = i + 1;
            v[e].push_back(w);
            tasks.push_back({e, w[0], w[1]});
        }
        vector <int> ans;
        bool pos = true;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(auto j : v[i]) {
                sum += j[1];
            }
            if(sum < 100) {
                pos = false;
                break;
            }
        }
        if(!pos) {
            cout << -1 << '\n';
            continue;
        }
        vector <int> time_taken(n, 0);
        for(int i = 0; i < n; i++) {
            vector<pair<int, int>> dp(101, {-1, -1});
            int x = v[i].size();
            vector<vector<int>> prev(x, vector<int>(101, -1));
            dp[0] = {0, 0};
            for(auto j : v[i]) {
                vector<pair<int, int>> ndp(101, {-1, -1});
                for(int i = 0; i < 100; i++) {
                    ndp[i] = dp[i];
                }
                if(i - )
            }
            // for(auto j : v[i]) {
            //     vector<vector<int>> change;
            //     for(int i = 0; i < 100; i++) {
            //         if(dp[i].first == -1) continue;
            //         int comp = i + j[1];
            //         if(comp > 100) comp = 100;
            //         if(dp[comp].first == -1 || (dp[comp].first > dp[i].first + j[0])) {
            //             // change.push_back({comp, dp[i].first + j[0], i, j[2]});
            //             change.push_back({comp, i, j[0], j[2]});
            //             // dp[comp].first = dp[i].first + j[0];
            //             // prev[comp] = i;
            //             // dp[comp].second = j[2];
            //         }
            //     }
            //     for(auto c : change) {
            //         int comp = c[0];
            //         if(dp[comp].first == -1 || (dp[comp].first > dp[c[1]].first + c[2])) {
            //             prev[comp] = c[1];
            //             dp[comp].second = c[3];
            //             dp[comp].first = dp[c[1]].first + c[2];
            //         }
            //     }
            // }

            int curr = 100;
            time_taken[i] = dp[100].first;
            while(curr > 0) {
                ans.push_back(dp[curr].second);
                cout << i << " " << curr << " " << dp[curr].second << '\n';
                curr = prev[curr];
            }
        }
        for(int i = 1; i < n; i++) {
            time_taken[i] += time_taken[i - 1];
        }
        for(int i = 0; i < n; i++) {
            if(time_taken[i] > a[i]) {
                pos = false;
                break;
            }
        }
        if(!pos) {
            cout << -1 << '\n';
            continue;
        }
        cout << (int)ans.size() << '\n';
        for(auto i : ans) cout << i << " ";
        cout << '\n';
    }
    
    return 0;
}