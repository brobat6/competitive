#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector <int> v(n);
    int total = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        total += v[i];
    }
    if(total <= k) {
        cout << 1;
        return 0;
    }
    int l = ceil(log2(n)) + 2;
    vector<vector<int>> nx(2*n, vector<int>(l, 2*n - 1));
    int i = 0, j = 0, sum = v[0];
    while(i < n) {
        nx[i][0] = (j + 1) % n;
        if(sum + v[(j + 1) % n] > k) {
            sum -= v[i];
            i++;
        } else {
            j = (j + 1) % n;
            sum += v[j];
        }
    }
    for(int i = 0; i < n; i++) {
        if(nx[i][0] <= i) {
            nx[i][0] += n;
        }
    }
    for(int i = n; i < 2*n; i++) {
        nx[i][0] = min(nx[i % n][0] + n, 2*n - 1);
    }
    for(int j = 1; j < l; j++) {
        for(int i = 0; i < 2*n; i++) {
            nx[i][j] = nx[nx[i][j - 1]][j - 1];
        }
    }

    int ans = n;
    for(int i = 0; i < n; i++) {
        // Find lowest LCA that is >= i + n.
        int x = i;
        int curr = 0;
        for(int j = l - 1; j >= 0; j--) {
            if(nx[x][j] >= i + n) {
                ans = min(curr + (1<<j), ans);
            } else {
                x = nx[x][j];
                curr += (1<<j);
            }
        }
    }
    cout << ans;
    
    return 0;
}