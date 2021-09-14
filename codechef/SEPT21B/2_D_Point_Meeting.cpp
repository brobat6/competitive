#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

const double EPS = 1e-9;

int n;
vector <double> x;
vector <double> y;
vector <pair<double, double>> store;

struct line {
    double a, b, c;
};

double det(double a, double b, double c, double d) {
    return a*d - b*c;
}

bool intersect(line m, line n, pair<double, double> & res) {
    double zn = det(m.a, m.b, n.a, n.b);
    if (abs(zn) < EPS)
        return false;
    res.first = -det(m.c, m.b, n.c, n.b) / zn;
    res.second = -det(m.a, m.c, n.a, n.c) / zn;
    return true;
}

int solve(double a, double b, double c, double d) {
    // convert (a, b) to (c, d).
    if(abs(a-c)<EPS && abs(b-d)<EPS) return 0;
    if(abs(a-c)<EPS || abs(b-d)<EPS || abs(abs(a-c)-abs(b-d))<EPS) return 1;
    return 2;
}

void solve() {
    int n;
    cin >> n;
    x.resize(n); y.resize(n); store.clear();
    forn(i, 0, n) cin >> x[i];
    forn(i, 0, n) cin >> y[i];
    forn(i, 0, n) store.push_back({x[i], y[i]});
    int arr[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};
    forn(i, 0, n) forn(j, 0, n) forn(a, 0, 4) forn(b, 0, 4) {
        line l1;
        l1.a = arr[a][1];
        l1.b = -arr[a][0];
        l1.c = y[i]*arr[a][0] - x[i]*arr[a][1];
        line l2;
        l2.a = arr[b][1];
        l2.b = -arr[b][0];
        l2.c = y[j]*arr[b][0] - x[j]*arr[b][1];
        pair<double, double> res;
        if(intersect(l1, l2, res)) store.push_back(res);
    }
    int ans = 1E18;
    for(auto i : store) {
        int t = 0;
        forn(j, 0, n) t += solve(x[j], y[j], i.first, i.second); 
        ans = min(ans, t);
    }
    cout << ans << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}