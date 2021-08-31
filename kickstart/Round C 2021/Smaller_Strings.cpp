#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

int n, k;
vector <int> v, a, p;
int ans;

bool compare() {
    vector <int> pl;
    if(n%2==0) {
        forn(i, 0, n/2) pl.push_back(v[i]);
        forn(i, 0, n/2) pl.push_back(pl[n/2 - i - 1]);
    }
    else {
        forn(i, 0, (n+1)/2) pl.push_back(v[i]);
        forn(i, 0, n/2) pl.push_back(v[n/2 - i - 1]);
    }
    forn(i, 0, n) {
        if(i == n-1 && v[i]==pl[i]) return false;
        if(v[i]<pl[i]) return false;
        if(v[i]>pl[i]) return true;
    }
    return true;
}

void solve() {
    cin >> n >> k;
    v.clear();
    p.clear();
    ans = 0;
    forn(i, 0, n) {
        char temp;
        cin >> temp;
        v.push_back(temp - 'a');
    }
    p.push_back(1);
    forn(i, 1, (n+1)/2) {
        p.push_back((p[i-1] * k) % MOD);
    }
    reverse(p.begin(), p.end());
    forn(i, 0, (n+1)/2) {
        ans += p[i] * v[i];
        ans %= MOD;
    }
    if(compare()) ans += 1;
    ans %= MOD;
    cout << ans << endl;
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