#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    string s;
    cin >> s;
    map<char, int> m;
    int n = s.size();
    forn(i, 0, n) m[s[i]] += 1;
    vector<pair<int, char>> v;
    for(auto i : m) v.push_back({i.second, i.first});
    sort(v.begin(), v.end(), greater<pair<int, char>>());
    int x = v.size();
    if(v[0].first > n/2) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    char ans[n];
    forn(i, 0, n) ans[i] = '0';
    for(auto i : v) {
        int x = i.first;
        char c = i.second;
        forn(j, 0, n) {
            if(x==0) break;
            if(ans[j]=='0' && s[j]!=c) {
                ans[j] = c;
                x--;
            }
        }
    }
    vector<int> zero;
    forn(i, 0, n) if(ans[i]=='0') zero.push_back(i);
    char f = v[x-1].second;
    char count = zero.size();
    int curr = 0;
    forn(i, 0, n) {
        if(curr==count) break;
        if(ans[i]=='0') continue;
        if(s[i]==f) continue;
        if(s[zero[curr]]==ans[i]) continue;
        ans[zero[curr]] = ans[i];
        ans[i] = f;
        curr++;
    }   
    forn(i, 0, n) cout << ans[i];
    cout << endl;
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