#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int x;
    cin >> x;
    while(x % 4 != 2) {
        x++;
    }
    cout << x;
    
    return 0;
}