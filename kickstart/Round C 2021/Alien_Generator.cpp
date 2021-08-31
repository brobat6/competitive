#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

vector <int> f;
void find_factors(int n) {
    for(int i=1; i<=sqrt(n); i++) {
        if(n%i==0) {
            f.push_back(i);
            if(n/i!=i) f.push_back(n/i);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    f.clear();
    find_factors(2*n);
    vector <int> ans;
    for(auto d : f) {
        int x = n - (d*(d+1)/2);
        if(x%d==0 && x/d>=0) ans.push_back(x/d + 1);  
    }
    cout << ans.size() << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    forn(I, 0, T) {
        cout << "Case #" << I+1 << ": ";
        solve();
    }

    return 0;
}