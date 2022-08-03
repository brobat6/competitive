#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(int n) {
    if(n == 1) {
        cout << 1 << " ";
        return;
    }
    solve(n - 1);
    cout << n << " ";
    solve(n - 1);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    solve(n);
    
    return 0;
}