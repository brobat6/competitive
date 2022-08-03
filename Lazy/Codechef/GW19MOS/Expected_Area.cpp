#include <bits/stdc++.h>
using namespace std;
#define int long long

#define double long double
#define pt pair<double, double>
#define x first
#define y second

double area(vector<pt>& v) {
    v.push_back(v.front());
    int n = v.size();
    double ans = 0.0;
    for(int i = 0; i < n - 1; i++) {
        ans += (v[i].x * v[i + 1].y);
        ans -= (v[i + 1].x * v[i].y);
    }
    return ans/2;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector <pair<int, int>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y;
    }
    vector <pt> w(n);
    for(int i = 0; i < n; i++) {
        w[i].x = (v[i].x + v[(i + 1) % n].x) / 2.0;
        w[i].y = (v[i].y + v[(i + 1) % n].y) / 2.0;
    }
    cout << setprecision(15) << area(w);
    
    return 0;
}