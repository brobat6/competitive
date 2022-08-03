#include <bits/stdc++.h>
using namespace std;
#define int long long

vector <int> parent;

int find(int x) {
    if(x==parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    int c = find(a);
    int d = find(b);
    if(d!=c) parent[d] = c;
}

bool comp_r(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}

bool comp_l(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    mt19937 rng_32(chrono::steady_clock::now().time_since_epoch().count());
    int t;
    cin >> t;
    clock_t start = clock();
    while(t--) {
        int n;
        cin >> n;
        parent.resize(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
        vector<vector<int>> r, b;
        vector<vector<int>> ugh(n);
        for(int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            if(x == 0) {
                r.push_back({i, y, z});
            } else {
                b.push_back({i, y, z});
            }
            ugh[i] = {i, x, y, z};
        }
        sort(ugh.begin(), ugh.end(), [&](vector <int> a, vector <int> b) {
            return a[3] < b[3];
        });
        if(((int)r.size() == 0)|| ((int)b.size() == 0)) {
            cout << n << '\n';
            continue;
        }
        for(int i = 1; i < n; i++) {
            if(ugh[i][1] != ugh[i - 1][1]) {
                if(ugh[i - 1][3] >= ugh[i][2]) {
                    unite(ugh[i][0], ugh[i - 1][0]);
                }
            }
        }
        sort(r.begin(), r.end(), comp_r);
        sort(b.begin(), b.end(), comp_l);
        int j = 0;
        int mx = -1E18;
        for(int i = 1; i < (int)r.size(); i++) {
            // check if r[i] and r[i - 1] are connected.
            int L = min(r[i][2], r[i - 1][2]);
            int R = max(r[i][1], r[i - 1][1]);
            while((j < (int)b.size()) && (b[j][1] <= L)) {
                mx = max(mx, b[j][2]);
                j++;
            }
            if(mx >= R) {
                unite(r[i][0], r[i - 1][0]);
            }
        }
        for(int i = 1; i < n; i++) {
            if(ugh[i][1] != ugh[i - 1][1]) {
                if(ugh[i - 1][3] >= ugh[i][2]) {
                    unite(ugh[i][0], ugh[i - 1][0]);
                }
            }
        }
        sort(b.begin(), b.end(), comp_r);
        sort(r.begin(), r.end(), comp_l);
        j = 0;
        mx = -1E18;
        for(int i = 1; i < (int)b.size(); i++) {
            // check if r[i] and r[i - 1] are connected.
            int L = min(b[i][2], b[i - 1][2]);
            int R = max(b[i][1], b[i - 1][1]);
            while((j < (int)r.size()) && (r[j][1] <= L)) {
                mx = max(mx, r[j][2]);
                j++;
            }
            if(mx >= R) {
                unite(b[i][0], b[i - 1][0]);
            }
        }
    
        for(int i = 1; i < n; i++) {
            if(ugh[i][1] != ugh[i - 1][1]) {
                if(ugh[i - 1][3] >= ugh[i][2]) {
                    unite(ugh[i][0], ugh[i - 1][0]);
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(i == find(i)) cnt++;
            // cout << i << " " << find(i) << '\n';
        }
        cout << cnt << '\n';
    }
    
    return 0;
}