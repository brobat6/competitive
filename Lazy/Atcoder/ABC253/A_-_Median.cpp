#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b, c;
    cin >> a >> b >> c;
    if(b >= a && b <= c) cout << "Yes";
    else if(b <= a && b >= c) cout << "Yes";
    else cout << "No";
    
    return 0;
}