#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> make_concat(vector<int>& p, int n) {
    vector <int> q(n, -1);
    int done = -1;
    set <int> left;
    for(int i = 0; i < n; i++) left.insert(i);
    for(int i = 0; i < n; i++) {
        if(p[i] > done) {
            done = p[i];
            q[p[i]] = 1; 
            left.erase(p[i]);
        } else {
            auto x = left.begin();
            if(p[i] != (*x)) {
                return q;
            }
            q[p[i]] = 0;
            left.erase(x);
        }
    }
    for(int i = 0; i < n; i++) {
        cout << q[i] << " ";
    }
    cout << '\n';
    return q;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    n *= 2;
    vector <int> p(n), q(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        --p[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> q[i];
        --q[i];
    }
    make_concat(p, n);
    
    return 0;
}