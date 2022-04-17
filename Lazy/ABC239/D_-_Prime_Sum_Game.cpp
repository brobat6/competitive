#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

bool is_prime(int x) {
    if(x < 2) return false;
    if(x == 2) return true;
    for(int i = 2; i < x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for(int i = a; i <= b; i++) {
        bool f = false;
        for(int j = c; j <= d; j++) {
            if(is_prime(i + j)) {
                // cout << i + j << endl;
                f = true;
                break;
            }
        }
        if(!f) {
            cout << "Takahashi";
            return;
        }
    }
    cout << "Aoki";
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T = 1;
    // cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}