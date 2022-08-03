#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        set <int> f;
        for(int i = 1; i <= sqrt(n); i++) {
            if(n % i == 0) {
                f.insert(i);
                f.insert(n - i);
                f.insert(n/i);
                f.insert(n - (n/i));
            }
        }
        cout << (int)f.size() - 2 << '\n';
    }
    
    return 0;
}