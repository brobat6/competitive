#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a > c) {
        swap(a, c);
        swap(b, d);
    }
    if(c >= b) {
        cout << 0;
    } else if(b < d) {
        cout << b - c;
    } else {
        cout << d - c;
    }
    
    return 0;
}