#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

void solve() {
    string s;
    cin >> s;
    map<int, int> m;
    int vow = 0, con = 0;
    int n = s.length();
    forn(i, 0, 26) m[i] = 0;
    forn(i, 0, n) m[s[i]-'A']++;
    // for(auto i : m) cout << i.first << " " << i.second << endl;
    vow = m[0] + m[4] + m[8] + m[14] + m[20];
    con = n - vow;
    vector <int> v;
    v.push_back(con + 2*(vow - m[0]));
    v.push_back(con + 2*(vow - m[4]));
    v.push_back(con + 2*(vow - m[8]));
    v.push_back(con + 2*(vow - m[14]));
    v.push_back(con + 2*(vow - m[20]));
    forn(i, 0, 26) {
        if(i==0||i==4||i==8||i==14||i==20) continue;
        v.push_back(vow + 2*(con - m[i]));
    }
    sort(v.begin(), v.end());
    cout << v[0] << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("consistency_chapter_1_input.txt", "r", stdin);
    // freopen("consistency_chapter_1_output.txt", "w", stdout);

    int T = 1;
    cin >> T;
    forn(I, 1, T+1) {
        cout << "Case #" << I << ": ";
        solve();
    }

    return 0;
}