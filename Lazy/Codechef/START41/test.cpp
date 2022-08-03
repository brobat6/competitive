#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int t = 100;
    cout << t << '\n';
    int n = 6;
    vector <int> v(n);
    iota(v.begin(), v.end(), 1);
    for(int i = 1; i <= t; i++) {
        shuffle(v.begin(), v.end(), rng);
        cout << n << '\n';
        for(auto i : v) cout << i << " ";
        cout << '\n';
    }
    
    return 0;
}