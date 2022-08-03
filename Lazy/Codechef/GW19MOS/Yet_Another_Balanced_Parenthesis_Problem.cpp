#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 100100;

string ans;

void add(int x) {
    for(int i = 0; i < x; i++) ans += '(';
    for(int i = 0; i < x; i++) ans += ')';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        n /= 2;
        k /= 2;
        if(n == k || k == 1 || k == 2) {
            cout << -1 << '\n';
            continue;
        }
        ans.clear();
        if(k == 3) {
            if(n % 2 == 1) {
                ans += '(';
                for(int i = 0; i < n/2; i++) add(2);
                ans += ')';
                cout << ans << '\n';
                continue;
            }
            for(int i = 0; i < n/2; i++) add(2);
            cout << ans << '\n';
            continue;
        }
        if(k == 4) {
            if(n % 3 == 0) for(int i = 0; i < n/3; i++) add(3);
            else if(n % 3 == 1) {
                add(2);
                add(3);
                add(2);
                n -= 7;
                for(int i = 0; i < n/3; i++) add(3);
            } else {
                for(int i = 0; i < n/3; i++) add(3);
                add(2);
            }
            cout << ans << '\n';
            continue;
        }
        if(n == k + 1) {
            add(k - 1);
            add(2);
            cout << ans << '\n';
            continue;
        }
        if(k == 6 && n == 11) {
            add(4);
            add(4);
            add(3);
            cout << ans << '\n';
            continue;
        }
        set <int> left;
        for(int i = 0; i <= n; i++) left.insert(i);
        vector <int> prev(n + 1, -1);
        queue <int> q;
        for(int i = k/2 + 1; i < k; i++) {
            left.erase(i);
            prev[i] = 0;
            q.push(i);
        }
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            while(!left.empty()) {
                auto x = left.lower_bound(curr + k/2 + 1);
                if(x == left.end()) break;
                int nx = *x;
                if(nx >= curr + k) break;
                prev[nx] = curr;
                q.push(nx);
                left.erase(x);
            }
        }
        // for(int i = 0; i <= n; i++) cout << prev[i] << " "; cout << '\n';
        int curr = n;
        while(curr) {
            add(curr - prev[curr]);
            curr = prev[curr];
        }
        cout << ans << '\n';
    }
    
    return 0;
}