#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = (int)1E18;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    multiset<int> ms;
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int a;
        cin >> a;
        if(a == 1) {
            int b;
            cin >> b;
            ms.insert(b);
        } else if(a == 2) {
            int b, c;
            cin >> b >> c;
            for(int j = 0; j < c; j++) {
                auto x = ms.lower_bound(b);
                if((*x) == b) {
                    ms.erase(x);
                } else {
                    break;
                }
            }
        } else {
            int x = *ms.begin();
            int y = *(--ms.end());
            cout << y - x << '\n';
        }
    }
    
    return 0;
}