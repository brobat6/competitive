#include <bits/stdc++.h>
using namespace std;
#define int long long

int sum(int A, int N) {
    // sum of multiples of a between 1 and n.
    int n = N/A + 1;
    int d = A;
    int s = n*(n - 1)*d/2;
    return s;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, a, b;
    cin >> n >> a >> b;
    cout << sum(1, n) - sum(a, n) - sum(b, n) + sum(a*b/__gcd(a, b), n);
    
    return 0;
}