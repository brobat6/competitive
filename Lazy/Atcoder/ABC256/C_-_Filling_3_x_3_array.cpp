#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int h[3], w[3];
    for(int i = 0; i < 3; i++) cin >> h[i];
    for(int i = 0; i < 3; i++) cin >> w[i];
    int cnt = 0;
    for(int a = 1; a <= 30; a++) {
        for(int b = 1; b <= 30; b++) {
            int c = h[0] - a - b;
            if(c <= 0) continue;
            for(int d = 1; d <= 30; d++) {
                int g = w[0] - a - d;
                if(g <= 0) continue;
                for(int e = 1; e <= 30; e++) {
                    int H = w[1] - b - e;
                    if(H <= 0) continue;
                    int f = h[1] - d - e;
                    if(f <= 0) continue;
                    int i = h[2] - g - H;
                    if(i <= 0 || i != w[2] - c - f) continue;
                    cnt++;
                }
            }
        }
    }
    cout << cnt << '\n';
    
    return 0;
}