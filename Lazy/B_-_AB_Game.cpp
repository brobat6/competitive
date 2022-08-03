#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, a, b;
    cin >> n >> a >> b;
    if(n < a) cout << 0;
    else cout << (n/a - 1)*min(a, b) + min(b, n - a*(n/a) + 1);
    
    return 0;
}