#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector <int> fact(22);
    fact[0] = 1;
    for(int i = 1; i < 22; i++) {
        fact[i] = fact[i - 1] * i;
    }
    
    return 0;
}