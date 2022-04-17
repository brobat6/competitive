#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

int n, k;
vector <int> a, b;
int ans;

bool check(int x) {
    // Check if number of elements with sum <= x is >= k
    int cnt = 0;
    forn(i, 0, n) {
        cnt += (upper_bound(b.begin(), b.end(), x - a[i]) - b.begin());
    }
    if(cnt >= k) ans = x;
    return (cnt >= k);
}

void solve() {
    cin >> n >> k;
    a.resize(n); b.resize(n);
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, n) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int left = 0;
    for(int x = a[n - 1] + b[n - 1]; x > 0; x >>= 1) {
        if(!check(left + x)) {
            left += x;
        }
    }
    cout << ans << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}