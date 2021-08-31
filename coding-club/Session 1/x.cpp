// https://www.codechef.com/problems/BITMASK4

#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int func() {
    int n;
    int a,b,c;
    int max = 0;
    double d;
    cin >> n;
    map <double, set<double>> m;
    for (int i = 1; i<=n; i++) {
        cin >> a >> b >> c;
        if(a==0) {
            d = a/b;
            m[d].insert(c/b);
        }
        else {
            d = b/a;
            m[d].insert(c/a);
        }
        if (m[d].size() > max) {
            max = m[d].size();
        }
    }
    cout << max << endl;
    return 0;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i<=t; i++) {
        func();
    }
    return 0;
}