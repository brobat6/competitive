#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 800100;
const int MOD = 1000000007;

int dp[MAXN];
int X[MAXN];
int O[MAXN];
vector <char> v;

void solve() {
    int n;
    cin >> n;
    v.resize(n);
    forn(i, 0, n) cin >> v[i];
    int pos_o = -1;
    int pos_x = -1;
    forn(i, 0, n) {
        if(v[i]=='X') pos_x = i;
        if(v[i]=='O') pos_o = i;
        X[i] = pos_o;
        O[i] = pos_x;
    }
    dp[0] = 0;
    forn(i, 1, n) {
        if(v[i]=='F') dp[i] = dp[i-1];
        else if(v[i]=='X') {
            if(X[i-1] >= O[i-1]) dp[i] = dp[i-1] + X[i] + 1;
            else dp[i] = dp[i-1];
        }
        else {
            if(O[i-1] >= X[i-1]) dp[i] = dp[i-1] + O[i] + 1;
            else dp[i] = dp[i-1];
        }
    }
    int ans = 0;
    forn(i, 0, n) ans = (ans + dp[i]) % MOD;
    cout << ans << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("weak_typing_chapter_2_input.txt", "r", stdin);
    // freopen("weak_typing_chapter_2_output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    forn(I, 1, T + 1) {
        cout << "Case #" << I << ": ";
        solve();
    }

    return 0;
}