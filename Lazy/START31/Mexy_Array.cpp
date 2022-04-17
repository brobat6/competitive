#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    vector <int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector <int> a(n + 1, -1);
    map<int, bool> done;
    for(int i = n - 1; i >= 0; i--) {
        if(b[i] == -1) continue;
        if(!done[b[i]]) {
            done[b[i]] = true;
            a[i + 1] = b[i];
        }
    }
    int curr = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == -1) {
            while(done[curr]) curr++;
            a[i] = curr++;
        }
    }
    map<int, int> check;
    curr = 0;
    bool pos = true;
    for(int i = 0; i < n; i++) {
        if(a[i] == curr) {
            check[curr] = true;
            while(check[curr]) curr++;
        } else if(a[i] > curr) {
            check[a[i]] = true;
        }
        if(b[i] == -1) continue;
        else {
            if(curr != b[i]) pos = false;
        }
    }
    if(!pos) {
        cout << -1 << endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}