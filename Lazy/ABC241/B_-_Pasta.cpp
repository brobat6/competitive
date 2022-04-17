#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    multiset <int> ms;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        ms.insert(t);
    }
    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if(ms.find(t) == ms.end()) {
            cout << "No";
            return 0;
        }
        ms.erase(ms.find(t));
    }
    cout << "Yes";
    
    return 0;
}