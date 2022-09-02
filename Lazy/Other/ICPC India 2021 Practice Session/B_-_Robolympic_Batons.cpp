#include <bits/stdc++.h>
using namespace std;

const int N = 500100;
// const int N = 10;
bitset<N> a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x) a.set(i);
    }
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b.set(x);
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        // cout << a << ' ' << b << '\n';
        if((a & b).count() == m) ans++;
        b <<= 1;
        if(b[n]) {
            b.reset(n);
            b.set(0);
        }
    }
    cout << ans;
    
    return 0;
}