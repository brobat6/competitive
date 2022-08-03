#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 200100;
const int MOD = (int)1E9 + 7;
const int INF = (int)9E18;
const char nl = '\n';

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        deque <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        if(v[0] != 0) {
            v.push_front(0);
            n++;
        }
        if(((int)v.size() == 2 && v[0] == 0 && v[1] == 100) || ((int)v.size() == 1 && v[0] == 0)) {
            for(int i = 1; i <= 100; i++) {
                cout << i << " ";
            }
            cout << '\n';
            continue;
        }
        if(v.back() == 100) {
            v.pop_back();
            n--;
        }
        vector <int> diff;
        for(int i = 1; i < n; i++) {
            diff.push_back(v[i] - v[i - 1]);
        }
        int g = 0;
        for(auto i : diff) {
            if(g == 0) g = i;
            else g = __gcd(g, i);
        }
        vector <int> ans;
        for(int i = 1; i <= g; i++) {
            if(g % i == 0) {
                ans.push_back(i);
            }
        }
        for(auto i : ans) cout << i << " ";
        cout << '\n';
    }
    
    return 0;
}