//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 100100

int n, m;
int arr[MAXN];
int num[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t;
    cin >> t;
while(t--) {
    cin >> n >> m;
    forn(i, max(n,m)+10) num[i] = 0;
    forn(i, n) {
        cin >> arr[i];
        arr[i] %= m;
        num[arr[i]] += 1;
    }
// 2 1 3 0 
// 3 4 4 0 2 1 1 1 
// 4 
// 6 4
    int ans = 0;
    if(num[0]!=0) ans += 1;
    if(m%2==0) {
        for(int i=1; i<(m/2); i++) {
            if(num[i]+num[m-i]>1) {
                ans += min(num[i],num[m-i]) + max(abs(num[i]-num[m-i])-1, 0);
            }
            else {
                ans += max(num[i],num[m-i]);
            }
        }
        if(num[m/2]!=0) ans+= 1;
    }
    else {
        for(int i=1; i<=(m/2); i++) {
            if(num[i]+num[m-i]>1) {
                ans += min(num[i],num[m-i]) + max(abs(num[i]-num[m-i])-1, 0);
            }
            else {
                ans += max(num[i],num[m-i]);
            }            
        }
    }
    // num[m] = 0;
    cout << ans << endl;
    // int ans = min(num[0],1);
    // for(int i=1; i<(m/2+m%2); i++) {
    //     if(num[i]+num[m-i]==1) ans += 1;
    //     else if(num[i]+num[m-i]==0) continue;
    //     else {
    //         ans += 
    //     }
    // }
}
    return 0;
}
