// https://www.codechef.com/problems/BITMASK4

#include <bits/stdc++.h>

using namespace std;

int func() {
    int n,a,b,max=0;
    cin >> n;
    double c;
    map <pair <int,int>, set<double>> m;
    for (int i=1;i<=n;i++) {
        // m[{1,1}].insert(i);
        cin >> a >> b >> c;
        int gcd = __gcd(a,b);
        a = a/gcd;
        b = b/gcd;
        c = c/gcd;
        m[{a,b}].insert(c);
        if (m[{a,b}].size()>max) {
            max = m[{a,b}].size();
        }
    }
    cout << max << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    int t;
    cin >> t;
    for (int i = 1; i<=t; i++) {
        func();
    }
    return 0;
}