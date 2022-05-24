#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector <int> a(n + 1, 0);
    vector <int> b(m + 1, 0);

    {
        vector <int> g(n + 1, 0);
        for(int i = 0; i < n; i++) {
            g[__gcd(i, n)]++;
        }
        vector <int> h(m + 1, 0);
        for(int i = 0; i < m; i++) {
            h[__gcd(i, m)]++;
        }
        for(int i = 1; i < n; i++) {
            for(int j = i; j <= n; j += i) {
                a[j] += g[i];
            }
        }
        for(int i = 1; i < m; i++) {
            for(int j = i; j <= m; j += i) {
                b[j] += h[i];
            }
        }
        a[0] = a[n];
        b[0] = b[m];
    }
    int q;
    cin >> q;
    // for(int i = 0; i < n; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << '\n';
    // for(int i = 0; i < m; i++) {
    //     cout << b[i] << " ";
    // }
    // cout << '\n';
    for(int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // cerr << (x2 - x1 + n) % n << " " << (y2 - y1 + m) % m << '\n';
        cout << a[(x2 - x1 + n) % n] * b[(y2 - y1 + m) % m] << '\n';
    }
    
    return 0;
}