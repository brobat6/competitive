#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int mx = 0;
    for(int i = 0; i < 2005; i++) {
        bool done = true;
        for(int j = 0; j < n; j++) {
            if(v[j] == i) {
                mx++;
                done = false;
                break;
            }
        }
        if(done) {
            cout << mx;
            return 0;
        }
    }
    
    return 0;
}