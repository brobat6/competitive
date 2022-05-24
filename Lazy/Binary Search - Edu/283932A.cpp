#include <bits/stdc++.h>
using namespace std;
#define int long long

bool check(int n, int h, int w, int x) {
    // return true if n rectangles can be packed in x*x square.
    int a = x/w;
    if(a == 0) return false;
    int b = n/a + min(n % a, 1LL);
    return (b * h <= x);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, h, w;
    cin >> w >> h >> n;
    if(w > h) swap(w, h);
    int l = 1;
    int r = (int)1E18 + 5;
    int ans = r;
    while(l <= r) {
        int m = (l + r)/2;
        if(check(n, h, w, m)) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << ans;
    
    return 0;
}