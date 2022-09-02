#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int k;
        cin >> k;
        vector<vector<int>> mat(n, vector<int>(n, 0));
        vector<int> deg(n, 0);
        for(int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            deg[x]++;
            deg[y]++;
            mat[x][y] = mat[y][x] = 1;
        }
        if(k == n*(n - 1)/2) {
            cout << 1 << '\n';
            for(int i = 1; i <= n; i++) cout << 1 << ' ';
            cout << '\n';
            cout << 1;
            cout << '\n';
            continue;
        }
        int head = max_element(deg.begin(), deg.end()) - deg.begin();
        vector <int> ha; // adj list of head.
        for(int i = 0; i < n; i++) {
            if(mat[i][head]) ha.push_back(i);
        }
        vector <int> deg_sat(n, 1);
        for(int i = 0; i < (int)ha.size(); i++) {
            for(int j = i + 1; j < (int)ha.size(); j++) {
                if(mat[ha[i]][ha[j]]) {
                    deg_sat[ha[i]]++;
                    deg_sat[ha[j]]++;
                }
            }
        }
        vector <int> heads; // list of all heads.
        for(auto i : ha) {
            if(deg[i] != deg_sat[i]) {
                heads.push_back(i);
            }
        }
        int head2;
        if(heads.empty()) {
            head2 = (head + 1) % n;
        } else {
            head2 = heads.front();
        }
        heads.clear();
        // cerr << head + 1 << ' ' << head2 + 1 << '\n';
        for(int i = 0; i < n; i++) {
            if(i == head || i == head2) continue;
            if(mat[i][head] && mat[i][head2]) {
                heads.push_back(i);
            }
        }
        heads.push_back(head);
        heads.push_back(head2);
        // for(auto i : heads) {
        //     cout << i + 1 << ' ';
        // }
        // cout << '\n';
        cout << (int)heads.size() << '\n';
        map<int, int> index;
        vector <int> ans(n, -1);
        for(int i = 0; i < (int)heads.size(); i++) {
            index[heads[i]] = i;
            ans[heads[i]] = i;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] && index.find(i) != index.end() && index.find(j) == index.end()) {
                    ans[j] = index[i];
                }
            }
        }
        for(int i = 0; i < n; i++) {
            cout << ans[i] + 1 << ' ';
        }
        cout << '\n';
        for(auto i : heads) cout << i + 1 << ' ';
        cout << '\n';
    }
    
    return 0;
}