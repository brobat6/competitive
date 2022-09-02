#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m, d, D;
        cin >> n >> m >> d >> D;
        if(d*n <= m && D*n >= m) {
            int done = 0;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(done == m) break;
                    cout << j + 1 << ' ' << (j + i) % n + 1 << '\n';
                    done++;
                }
            }
        } else {
            cout << -1 << '\n';
        }
    }
    
    return 0;
}