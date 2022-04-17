#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

int n, k;
vector <int> a, b;
int ans;

bool check(int x) {
    // Check if number of elements with sum <= x is >= k
    int cnt = 0;
    int i = 0;
    int j = n - 1;
    while(i < n && j >= 0) {
        if(a[i] + b[j] > x) {
            j--;
            continue;
        }
        cnt += (j + 1);
        i++;
    }
    if(cnt >= k) ans = x;
    return (cnt >= k);
}

int binary_search(int left, int right) {
    int ans = -1;
    while(left <= right) {
        int mid = (left + right)/2;
        if(!check(mid)) {
            left = mid + 1;
            ans = mid;
        }
        else {
            right = mid - 1;
        }
    }
    return ans + 1;
}

void solve() {
    cin >> n >> k;
    assert(1 <= n && n <= 100000);
    assert(1 <= k && k <= n*n);
    a.resize(n); b.resize(n);
    forn(i, 0, n) cin >> a[i];
    forn(i, 0, n) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if(k == n*n) {
        cout << a[n - 1] + b[n - 1];
        return;
    }
    if(k == 1) {
        cout << a[0] + b[0];
        return;
    }
    cout << binary_search(0, 2E9) << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}