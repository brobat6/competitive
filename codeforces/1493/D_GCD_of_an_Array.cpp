// https://codeforces.com/contest/1493/problem/D

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    long long n, q;
    cin >> n >> q;
    long long a[n];
    forn(i, n) cin >> a[i];
    long long index[n], x[n];
    forn(i, q) {
        cin >> index[i] >> x[i];
        --index[i];
        a[index[i]] *= x[i];
    }
    // Now we have the final array. Calculate it's GCD
    long long g = a[0];
    forn(i, n-1) {
        g = __gcd(g, a[i+1]);
    }
    // Now g contains final gcd. 
    long long ans[q];
    ans[q-1] = g;
    for(int i=(q-1); i>0; i--) {
        a[index[i]] /= x[i];
        g = __gcd(g, a[index[i]]);
        ans[i-1] = g;
    }
    forn(i, q) {
        ans[i] %= 1000000007;
    }
    forn(i, q) {
        cout << ans[i] << endl;
    }
    return 0;
}
