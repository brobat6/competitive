#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    multiset <int> ms;
    for(int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a;
        if(a == 1) {
            cin >> b;
            ms.insert(b);
        }
        if(a == 2) {
            cin >> b >> c;
            auto x = ms.upper_bound(b);
            if(x == ms.begin()) {
                cout << -1 << endl;
                continue;
            }
            bool done = false;
            for(int i = 0; i < c; i++) {
                if(x == ms.begin()) {
                    cout << -1 << endl;
                    done = true;
                    break;
                }
                --x;
            }
            if(!done) {
                cout << (*x) << endl;
            }
        }
        if(a == 3) {
            cin >> b >> c;
            auto x = ms.lower_bound(b);
            if(x == ms.end()) {
                cout << -1 << endl;
                continue;
            }
            bool done = false;
            for(int i = 1; i < c; i++) {
                ++x;
                if(x == ms.end()) {
                    cout << -1 << endl;
                    done = true;
                    break;
                }
            }
            if(!done) {
                cout << (*x) << endl;
            }
        }
    }
    
    return 0;
}