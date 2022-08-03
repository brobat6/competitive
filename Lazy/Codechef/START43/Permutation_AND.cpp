#include <bits/stdc++.h>
using namespace std;
#define int long long

void out(vector <int> &a, vector <int> &b) {
    int n = a.size();
    vector <int> c(n, 0);
    vector <int> d(n, 0);
    for(int i = 0; i < n; i++) {
        assert((a[i] & b[i]) == 0);
        c[a[i] - 1] = 1;
        d[b[i] - 1] = 1;
    }
    int e = accumulate(c.begin(), c.end(), 0ll);
    int f = accumulate(d.begin(), d.end(), 0ll);
    assert(e == n && f == n);
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << '\n';
    for(int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << '\n';
}

int invert(int x) {
    int y = x;
    for(int i = 0; i < 30; i++) {
        if((1<<i) > x) break;
        y ^= (1<<i); 
    }
    return y;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n == 1) {
            cout << "1\n1\n";
            continue;
        }
        if(n % 2 == 1) {
            cout << -1 << '\n';
            continue;
        }
        vector <int> a(n), b(n, 0);
        for(int i = 0; i < n; i++) {
            a[i] = i + 1;
        }
        for(int i = n - 1; i >= 0; i--) {
            if(b[i] != 0) continue;
            int x = invert(a[i]);
            b[i] = x;
            b[x - 1] = a[i];
        }
        out(a, b);
    }
    
    return 0;
}