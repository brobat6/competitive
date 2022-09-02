#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int M = 998244353;
    long long n;
    cin >> n;
    n %= M;
    cout << (n < 0 ? M + n : n);
    
    return 0;
}