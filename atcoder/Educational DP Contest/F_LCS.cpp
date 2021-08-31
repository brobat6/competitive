#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 3100
#define MOD 1000000007

string s, t;
int n, m;
int dp[MAXN][MAXN];
vector <char> ans;

void func(int x, int y) {
    if(dp[x][y]==0) return;
    if(dp[x-1][y] < dp[x][y] && dp[x][y-1] < dp[x][y]) {
        ans.push_back(s[x-1]);
        func(x-1, y-1);
    }
    else {
        if(dp[x-1][y] > dp[x][y-1]) func(x-1, y);
        else func(x, y-1);
    }
}

void solve() {
    cin >> s >> t;
    n = s.length();
    m = t.length();
    forn(i, 0, n+1) forn(j, 0, m+1) dp[i][j] = 0;
    forn(i, 1, n+1) {
        forn(j, 1, m+1) {
            if(s[i-1]==t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    func(n, m);
    reverse(ans.begin(), ans.end());
    for(auto i : ans) cout << i;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}