#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int h, w;
    cin >> h >> w;
    int x1 = -1;
    int y1 = -1;
    int x2 = -1;
    int y2 = -1;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            char c;
            cin >> c;
            if(c == 'o') {
                if(x1 == -1) {
                    x1 = i;
                    y1 = j;
                } else {
                    x2 = i;
                    y2 = j;
                }
            }
        }
    }
    cout << abs(x1 - x2) + abs(y1 - y2);
    
    return 0;
}