#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 1000100
#define MOD 1000000007

void func(int n) {
    double gamma = 0.5772156649;
    double p = log(n);
    cout << setprecision(15) << gamma + p << endl;
}

void solve() {
    int n;
    cin >> n;
    if(n > MAXN) {
        func(n);
        return;
    }
    double dp[n+1];
    dp[1] = 1.000000000;
    double sum = 1;
    forn(i, 2, n+1) {
        dp[i] = 1 + (sum/i);
        sum += dp[i];
    }
    cout << setprecision(15) << dp[n] << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int T = 1;
    cin >> T;
    forn(I, 1, T+1) {
        cout << "Case #" << I << ": ";
        solve();
    }

    return 0;
}