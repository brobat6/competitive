//

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 200100
#define MOD 1000000007

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t;
    cin >> t;
while(t--) {
    vector<int> v;
    cin >> n;
    int arr[n][2];
    forn(i, n) {
        cin >> arr[i][0];
        arr[i][1] = i;
    }
    sort(arr, arr+n);
    int grr[n];
    grr[0] = arr[0][0];
    for(int i=1; i<n; i++) {
        grr[i] = arr[i][0] + grr[i-1];
    }
    int ans = 0;
    forn(i, n-1) {
        if(grr[i]>=arr[i+1][0]) {
            ans += 1;
            v.push_back(arr[i][0]);
        }
    }
    cout << ans+1 << "\n";
    v.push_back(arr[n-1][0]);
    sort(v.begin(), v.end());
    for(auto it: v) {
        cout << it << " ";
    }
    cout << "\n";
}
    return 0;
}

