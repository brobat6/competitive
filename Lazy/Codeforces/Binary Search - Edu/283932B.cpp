#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector <double> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    double eps = 1e-7;
    double l = 0.0;
    double r = 2e7;
    double ans = 0.0;
    while((r - l) > eps) {
        double m = (l + r)/2;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt += floor(v[i] / m);
        }
        bool check = (cnt >= k);

        if(check) {
            ans = m;
            l = m + eps;
        } else {
            r = m - eps;
        }
    }
    cout << setprecision(10) << ans;
    
    return 0;
}