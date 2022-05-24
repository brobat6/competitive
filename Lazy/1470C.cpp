#include <bits/stdc++.h>
using namespace std;
#define int long long

int query(int q) {
    int x;
    cout << "? " << q << endl;
    cin >> x;
    return x;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    query(1);
    if(n <= 600) {
        for(int i = 0; i < (n/2) + 5; i++) {
            query(1);
        }
        int x = 0;
        int xi = 0;
        for(int i = 0; i < n; i++) {
            int y = query(i + 1);
            if(y > x) {
                xi = i;
                x = y;
            }
        }
        cout << "! " << (xi - 1 + n) % n + 1 << endl;
    } else {
        bool found = false;
        for(int i = 1; i <= 455; i++) {
            int xx = i*(i + 1)/2; // 0-indexed.
            int c = query(xx % n + 1);
            if(c != k) {
                found = true;
                // found our range - we will DEFINITELY find our range. 
                int x = 0;
                int xi = 0;
                for(int j = xx + 1; j <= xx + 1 + i; j++) {
                    int y = query(j % n + 1);
                    if(y > x) {
                        xi = j % n;
                        x = y;
                    }
                }
                int y;
                int j = (i - 1)*i/2;
                y = query(j % n + 1);
                if(y > x) {
                    xi = j % n;
                    x = y;
                }
                j = (j + n - 1) % n;
                y = query(j % n + 1);
                if(y > x) {
                    xi = j % n;
                    x = y;
                }
                j = (j + 2) % n;
                y = query(j % n + 1);
                if(y > x) {
                    xi = j % n;
                    x = y;
                }
                cout << "! " << (xi - 1 + n) % n + 1 << endl;
                break;
            }
        }
        assert(found);
    }
    
    return 0;
}