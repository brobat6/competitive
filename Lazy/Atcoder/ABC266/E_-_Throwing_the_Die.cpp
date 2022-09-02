#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

ld solve(int a, int b, int c, int d, int e) {
    ld x1 = pow(5.0, a)/pow(6.0, a);
    ld x2 = pow(4.0, b)/pow(6.0, b);
    ld x3 = pow(3.0, c)/pow(6.0, c);
    ld x4 = pow(2.0, d)/pow(6.0, d);
    ld x5 = pow(1.0, e)/pow(6.0, e);
    ld ans = 6.0*(1 - x1);
    ans += x1*11/6*3*(1-x2);
    ans += x1*x2*15/6*2*(1-x3);
    ans += x1*x2*x3*18/6*6/4*(1-x4);
    ans += x1*x2*x3*x4*20/6*6/5*(1-x5);
    ans += x1*x2*x3*x4*x5*21/6;
    // cerr << x1 << ' ' << x2 << ' ' << x3 << ' ' << x4 << ' ' << x5 << ' ' << ans << '\n';
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    ld ans = 0.0;

    for(int x1 = 0; x1 < n; x1++) {
        for(int x2 = 0; x2 < n; x2++) {
            for(int x3 = 0; x3 < n; x3++) {
                for(int x4 = 0; x4 < n; x4++) {
                    ans = max(ans, solve(x1, x2, x3, x4, n - 1 - x1 - x2 - x3 - x4));
                    if(n >= 20) break;
                }
            }
        }
    }
    cout << setprecision(15) << ans;
    
    return 0;
}