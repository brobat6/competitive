#include <bits/stdc++.h>
using namespace std;
#define int long long

int ask(int i, int j) {
    cout << 1 << " " << i << " " << j << endl;
    int x; cin >> x;
    return x;
}

// what if weight of first item is 1.

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector <int> wt(n), val(n);
    int sum = 0;
    int value = 0;
    for(int i = 0; i < n; i++) {
        int l = sum;
        int ans;
        int needed = ask(i + 1, 10000);
        int r = sum + 105;
        while(l <= r) {
            int mid = (l + r)/2;
            int curr = ask(i + 1, mid);
            if(curr == needed) {
                ans = mid - sum;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        wt[i] = ans;
        val[i] = needed - value;
        sum += wt[i];
        value += val[i];
    }
    cout << 2 << endl;
    for(int i = 0; i < n; i++) cout << wt[i] << " ";
    cout << endl;
    for(int i = 0; i < n; i++) cout << val[i] << " ";
    cout << endl;
    
    return 0;
}