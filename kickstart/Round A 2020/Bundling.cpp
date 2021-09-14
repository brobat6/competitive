#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

int n, k;
vector <string> arr;
vector <pair<int, int>> st; //first -> the max val, second -> the index
set <int> s; // The indices still remaining.
int ans;

int compare(string &A, string &B) {
    if(B[0]=='0') return -1;
    forn(i, 0, min(A.length(), B.length())) {
        if(A[i] != B[i]) return i;
    }
    return min(A.length(), B.length());
}

void build(int v, int tl, int tr) {
    if(tl==tr) {
        st[v].first = compare(arr[tl], arr[tl + k - 1]);
        st[v].second = tl;
    }
    else {
        int tm = (tl + tr)/2;
        build(v*2, tl, tm);
        build(v*2 + 1, tm + 1, tr);
        st[v] = max(st[v*2], st[v*2 + 1]);
    }
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if(tl==tr) st[v] = {new_val, pos};
    else {
        int tm = (tl + tr)/2;
        if(pos <= tm) update(v*2, tl, tm, pos, new_val);
        else update(v*2 + 1, tm+1, tr, pos, new_val);
        st[v] = max(st[v*2], st[v*2 + 1]);
    }
}

void solve() {
    cin >> n >> k;
    arr.clear();
    arr.resize(n);
    st.clear();
    st.resize(4*n);
    s.clear();
    ans = 0;
    forn(i, 0, n) cin >> arr[i];
    sort(arr.begin(), arr.end());
    forn(i, n, n+k) arr.push_back("0");
    forn(i, -k, n + k) s.insert(i);
    build(1, 0, n - 1);
    // cout << st[1].first << " " << st[1].second << endl;
    forn(i, 0, n/k - 1) {
        ans += st[1].first;
        int x = st[1].second;
        auto temp = s.find(x);
        forn(j, 0, k - 1) --temp;
        forn(j, 0, k) {
            auto it = s.lower_bound(x);
            update(1, 0, n-1, *it, 0);
            s.erase(*it);
        }
        vector <int> v;
        forn(j, 0, 2*k) {
            v.push_back(*temp);
            ++temp;
        }
        // for(auto j : v) cout << j << " ";
        forn(j, 0, k) {
            if(v[j] < 0) continue;
            int c = compare(arr[v[j]], arr[v[j + k - 1]]);
            update(1, 0, n-1, v[j], c);
        }
    }
    ans += st[1].first;
    cout << ans << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int T = 1;
    cin >> T;
    forn(I, 1, T+1) {
        cout << "Case #" << I << ": ";
        solve();
    }

    return 0;
}