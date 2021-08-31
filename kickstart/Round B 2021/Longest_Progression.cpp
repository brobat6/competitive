    #include <bits/stdc++.h>
    using namespace std;

    #define int long long
    #define forn(i, a, n) for (int i = a; i < n; i++)
    #define MAXN 200100
    #define MOD 1000000007

    void solve() {
        int n;
        cin >> n;
        int arr[n];
        forn(i, 0, n) cin >> arr[i];
        if(n<4) {
            cout << n << endl;
            return;
        }
        if(n==4) {
            int x = 3;
            // First index
            if(arr[3]-arr[2]==arr[2]-arr[1]) x = 4;
            if(arr[0]-arr[1]==arr[1]-arr[2]) x = 4;
            if(arr[0]-arr[2]==2*(arr[2]-arr[3])) x = 4;
            if(arr[1]-arr[3]==2*(arr[0]-arr[1])) x = 4;
            cout << x << endl;
            return;
        }
        int s[n]; // Without change, length starting at i. 
        int e[n]; // Without change, length ending at i.
        e[0] = 1;
        e[1] = 2;
        forn(i, 2, n) {
            if(arr[i]-arr[i-1]==arr[i-1]-arr[i-2]) e[i] = e[i-1] + 1;
            else e[i] = 2;
        }
        s[n-1] = 1;
        s[n-2] = 2;
        for(int i = n - 3; i>=0; i--) {
            if(arr[i]-arr[i+1]==arr[i+1]-arr[i+2]) s[i] = s[i+1] + 1;
            else s[i] = 2;
        }
        vector<int> v;
        // Also check for index 1 and n - 2.
        for(int i = 2; i < n-2; i++) {
            // Assume that element i is changed.
            if(arr[i-2]-arr[i-1]==arr[i+1]-arr[i+2] && arr[i+1]-arr[i-1]==2*(arr[i-2]-arr[i-1])) {
                v.push_back(e[i-1] + 1 + s[i+1]);
            }
        }
        if(arr[2]-arr[0] == 2*(arr[3]-arr[2])) v.push_back(2 + s[2]);
        if(arr[n-3]-arr[n-1]==2*(arr[n-4]-arr[n-3])) v.push_back(2 + e[n-3]);
        sort(e, e + n);
        sort(v.begin(), v.end(), greater<int>());
        int ans = e[n-1] + 1;
        if(v.size()) {
            if(v[0] > ans) ans = v[0];
        }
        cout << min(ans, n) << endl;

    }

    int32_t main() {

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        // freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);
        
        int T = 1;
        cin >> T;
        forn(i, 1, T+1) {
            cout << "Case #" << i << ": ";
            solve();
        }

        return 0;
    }