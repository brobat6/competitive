#include <bits/stdc++.h>
using namespace std;
#define int long long

const int B = 600;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> query(q, vector<int>(4));
    for(int i = 0; i < q; i++) {
        cin >> query[i][0] >> query[i][1] >> query[i][2];
        if(query[i][0] == 1) {
            --query[i][1];
            --query[i][2];
            cin >> query[i][3];
        } else if(query[i][0] == 2) {
            --query[i][1];
        } else {
            --query[i][1];
            --query[i][2];
        }
    }
    vector<vector<int>> v(q/B + 5, vector<int>(m + 1, 0));
    int it = -1;
    for(int i = 0; i < q; i++) {
        if(i % B == 0) it++;
        if(query[i][0] == 1) {
            v[it][query[i][1]] += query[i][3];
            v[it][query[i][2] + 1] -= query[i][3];
        }
    }
    for(int i = 0; i <= it; i++) {
        int curr = 0;
        for(int j = 0; j < m; j++) {
            curr += v[i][j];
            v[i][j] = curr;
        }
    }
    // for(int i = 0; i <= it; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    // cout << 'F';
    vector <int> r(n, -1); // the last time-stamp when row was reset.
    for(int i = 0; i < q; i++) {
        if(query[i][0] == 1) continue;
        if(query[i][0] == 2) {
            r[query[i][1]] = i;
            continue;
        }
        int x = query[i][1];
        int y = query[i][2];
        int ans = 0;
        if(r[x] != -1) ans = query[r[x]][2];
        int b1 = r[x] / B;
        int b2 = i / B;
        if(b1 < 0) b1 = 0;
        if(b2 - b1 < 2) {
            for(int j = r[x] + 1; j < i; j++) {
                if(query[j][0] == 1) {
                    if(query[j][1] <= y && query[j][2] >= y) {
                        ans += query[j][3];
                    }
                }
            }
        } else {
            // cout << "HM";
            for(int j = b1 + 1; j < b2; j++) {
                ans += v[j][y];
            }
            for(int j = r[x] + 1; j < (b1 + 1)*B; j++) {
                if(query[j][0] == 1) {
                    if(query[j][1] <= y && query[j][2] >= y) {
                        ans += query[j][3];
                    }
                }
            }
            for(int j = b2*B; j < i; j++) {
                if(query[j][0] == 1) {
                    if(query[j][1] <= y && query[j][2] >= y) {
                        ans += query[j][3];
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}