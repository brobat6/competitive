#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            --v[i];
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            map <int, int> cnt;
            int temp = 0;
            int sub = 0;
            for(int j = 0; j < n; j++) {
                if(v[j] != i) {
                    cnt[v[j]]++;
                } else {
                    temp++;
                    pair<int, int> mx = {0, 0};
                    int sum = 0;
                    for(auto i : cnt) {
                        sum += i.second;
                        if(i.second > mx.second) {
                            mx = i;
                        }
                    }
                    int left = max(0ll, mx.second*2 - sum);
                    cnt.clear();
                    if(left >= 1) {
                        sub++;
                        left--;
                    }
                    if(left >= 1) {
                        cnt[mx.first] = left;
                    }
                }
            }
            pair<int, int> mx = {0, 0};
            int sum = 0;
            for(auto i : cnt) {
                sum += i.second;
                if(i.second > mx.second) {
                    mx = i;
                }
            }
            int left = max(0ll, mx.second*2 - sum);
            ans = max(ans, temp - sub - left);
        }
        cout << ans << '\n';
    }
    
    return 0;
}