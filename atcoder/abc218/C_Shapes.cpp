#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

bool comp(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

bool compare(vector<pair<int, int>> &A, vector<pair<int, int>> &B) {
    if(A.size() != B.size()) return false;
    forn(i, 0, A.size()) {
        if(A[i].first!=B[i].first || A[i].second!=B[i].second) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    char arr[n][n], brr[n][n];
    forn(i, 0, n) forn(j, 0, n) cin >> arr[i][j];
    forn(i, 0, n) forn(j, 0, n) cin >> brr[i][j];
    int t = n, l = n; // Find left-most and top-most points of A [origin].
    vector<pair<int, int>> A;
    forn(i, 0, n) forn(j, 0, n) {
        if(arr[i][j]=='#') {
            t = min(t, i);
            l = min(l, j);
        }
    }
    forn(i, 0, n) forn(j, 0, n) {
        if(arr[i][j]=='#') {
            A.push_back({i - t, j - l});
        }
    }
    // Now assume 4 orientations of B and solve.
    vector<pair<int, int>> B, C, D, E;
    int tb = n, lb = n, tc = n, lc = 0, td = 0, ld = n, te = 0, le = 0;
    forn(i, 0, n) forn(j, 0, n) {
        if(brr[i][j]=='#') {
            tb = min(tb, i); tc = tb;
            lb = min(lb, j); ld = lb;
            td = max(td, i); te = td;
            lc = max(lc, j); le = lc;
        }
    }
    forn(i, 0, n) forn(j, 0, n) {
        if(brr[i][j]=='#') {
            B.push_back({i - tb, j - lb});
            C.push_back({lc - j, i - tc}); // top-right, rotate counter-clockwise 
            D.push_back({j - ld, td - i}); // bottom-left, rotate clockwise
            E.push_back({te - i, le - j}); 
        }
    }
    sort(A.begin(), A.end(), comp);
    sort(B.begin(), B.end(), comp);
    sort(C.begin(), C.end(), comp);
    sort(D.begin(), D.end(), comp);
    sort(E.begin(), E.end(), comp);
    if(compare(A, B) || compare(A, C) || compare(A, D) || compare(A, E)) cout << "Yes";
    else cout << "No";
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}