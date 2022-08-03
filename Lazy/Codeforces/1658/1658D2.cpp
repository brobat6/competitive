#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

void solve() {
    int l, r;
    cin >> l >> r;
    int n = r - l + 1;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector <int> which(19, 0);
    for(int i = l; i <= r; i++) {
        int temp = i;
        for(int j = 0; j < 19; j++) {
            if(temp % 2) {
                which[j]++;
            }
            temp /= 2;
        }
    }
    vector <int> bits(19, 0);
    for(int i = 0; i < n; i++) {
        int temp = v[i];
        for(int j = 0; j < 19; j++) {
            if(temp % 2) {
                bits[j]++;
            }
            temp /= 2;
        }
    }
    int ans = 0;
    for(int i = 0; i < 19; i++) {
        if(bits[i] != which[i]) {
            ans += (1ll << i);
        }
    }
    cout << ans << endl;
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}