#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> v(n), w(n);
        map<int, int> m;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            w[i] = v[i];
            m[v[i]]++;
        }
        sort(w.begin(), w.end());
        for(int i = 0; i < n; i++) {
            int less = lower_bound(w.begin(), w.end(), v[i]) - w.begin();
            int more = n - (upper_bound(w.begin(), w.end(), v[i]) - w.begin());
            int eq = m[v[i]] - 1;
            if(less > more) swap(less, more);
            int diff = min(eq, more - less);
            less += diff;
            eq -= diff;
            cout << min(less, more)*2 + (eq/2)*2 + 1 << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}