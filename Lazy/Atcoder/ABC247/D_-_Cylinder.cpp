#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    deque <pair<int, int>> v;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if(a == 1) {
            int b, c;
            cin >> b >> c;
            v.push_back({b, c});
        }
        else {
            int c;
            cin >> c;
            int sum = 0;
            int done = 0;
            while(done < c) {
                int left = c - done;
                if(left < v[0].second) {
                    sum += (v[0].first * left);
                    v[0].second -= left;
                    done += left;
                }
                else {
                    sum += v[0].first * v[0].second;
                    done += v[0].second;
                    v.pop_front();
                }
            }
            cout << sum << endl;
        }
    }
    
    return 0;
}