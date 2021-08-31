// https://cp-algorithms.com/algebra/extended-euclid-algorithm.html

#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // int a,b,x,y;
    // cin >> a >> b;
    // int g = gcd(a,b,x,y);
    // cout << a << "." << x << " + " << b << "." << y << " = " << g;
    while(true) {
        int a,b,c1,c2,x,y;
        cin >> c1 >> a >> b >> c2;
        if((c1==0&&c2==0)&&(a==0&&b==0)) break;
        int c = c2 - c1;
        int g = gcd(a,b,x,y);
        if((c%g)!=0) {
            cout << "Impossible" << endl;
            continue;
        }
        // cout << a << "." << x << " + " << b << "." << y << " = " << g;
        // cout << a << " " << b << " " << g << endl;
        float k1 = (g*y);
        k1 /= a;
        float k2 = (g*x);
        k2 /= b;
        // cout << k1 << endl;
        // cout << k2 << endl;
        int k3 = floor(k1);
        int k4 = floor(k2);
        int k;
        if(a>=b) {
            if(k3<k4) k = k3;
            else k = k4;
        }
        else {
            if(k3<k4) k = k4;
            else k = k3;
        }
        // cout << k;
        y -= (k*a)/g;
        int ans = c2 + (b*y);
        cout << ans << endl;
    }
    return 0;
}
