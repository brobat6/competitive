#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    vector <int> v = { 1410, 1456, 1688, 1712};
    int g = v[0];
    for(int i = 1; i < 4; i++) {
        g = gcd(g, v[i]);
    }
    cout << g;

    return 0;
}