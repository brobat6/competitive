// https://codeforces.com/contest/1466/problem/A

#include <bits/stdc++.h>
using namespace std;
#define int long long

bitset<100100> A;
bitset<100100> B;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        A.reset();
        B.reset();
        int n;  
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for(int i = 1; i < n; i++) {
            int diff = arr[i] - arr[i - 1];
            A[diff] = 1;
            B <<= diff;
            B[diff] = 1;
            A = A | B;
            // cout << diff << " " << A << " " << B << '\n';
        }
        cout << (int)A.count() << '\n';
    }

    
    
    return 0;
}