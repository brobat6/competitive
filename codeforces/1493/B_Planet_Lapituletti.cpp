// https://codeforces.com/contest/1493/problem/B

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t;
    cin >> t;
while(t--) {
    int h, m;
    cin >> h >> m;
    string s;
    cin >> s;
    int h1, h2, m1, m2;
    h1 = int(s[0]);
    h2 = int(s[1]);
    m1 = int(s[3]);
    m2 = int(s[4]);
    cout << h1 << " " << h2 << endl;
}
    return 0;
}
