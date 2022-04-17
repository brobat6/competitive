#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    mt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());
    
    int t = 10;
    while(t--) {
        unordered_set <int> xx;
        int n = 5;
        int m = 20;
        while((int)xx.size() < n) {
            xx.insert(rng_64() % m);
        }
        vector <int> v;
        for(auto i : xx) v.push_back(i);
        sort(v.begin(), v.end());

        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += (v[i] % v[(i + 1)% n]);
        }
        cout << ans << endl;

        int mx = 0;
        vector <int> x(n);
        do {
            int temp = 0;
            for(int i = 0; i < n; i++) {
                temp += (v[i] % v[(i + 1) % n]);
            }
            if(temp > mx) {
                mx = temp;
                for(int i = 0; i < n; i++) {
                    x[i] = v[i];
                }
            }
        } while(next_permutation(v.begin(), v.end()));
        cout << mx << '\n';
        if(ans != mx) {
            cout << "FUCKING FOUND ONE, FINALLY!\n";
        }
    }
    
    return 0;
}