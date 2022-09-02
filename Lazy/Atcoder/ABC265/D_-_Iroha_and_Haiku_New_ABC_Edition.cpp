#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, p, q, r;
    cin >> n >> p >> q >> r;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector <int> w(n);
    w[0] = v[0];
    for(int i = 1; i < n; i++) {
        w[i] = w[i - 1] + v[i];
    }

    auto sum = [&](int x, int y) -> int {
        if(x == 0) return w[y];
        return w[y] - w[x - 1]; 
    };

    int i = 0, j = 1, k = 2, l = 3;
    while(l <= n) {
        while(i >= j) j++;
        while(j >= k) k++;
        while(k >= l) l++;
        if(l > n) break;
        assert(i < j && j < k && k < l);
        if(sum(i, j - 1) == p && sum(j, k - 1) == q && sum(k, l - 1) == r) {
            cout << "Yes";
            return 0;
        }
        if(sum(i, j - 1) > p) {
            i++;
        } else if(sum(i, j - 1) < p) {
            j++;
        } else if(sum(j, k - 1) > q) {
            j++;
        } else if(sum(j, k - 1) < q) {
            k++;
        } else if(sum(k, l - 1) > r) {
            k++;
        } else if(sum(k, l - 1) < r) {
            l++;
        }
    }
    cout << "No";
    return 0;
}