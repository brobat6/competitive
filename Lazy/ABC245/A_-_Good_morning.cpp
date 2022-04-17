#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a * 60 + b > c * 60 + d) cout << "Aoki";
    else cout << "Takahashi";
    
    return 0;
}