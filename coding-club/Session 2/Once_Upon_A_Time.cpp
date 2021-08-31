// https://codeforces.com/gym/100963/attachments (J - Once Upon a Time)

#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    while(true) {
        int n,m,a,k;
        cin >> n >> m >> a >> k;
        if((n==0&m==0)&&(a==0&&k==0)) break;
        int c = k-n;
        int x0, y0, g;
        if(find_any_solution(m,a,c,x0,y0,g)) {
            cout << x0 << " " << y0 << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }






    // freopen("once.in","r",stdin);
    // freopen("once.out","w",stdout);
    // while(true) {
    //     int n,m,a,k,r;
    //     cin >> n >> m >> a >> k;
    //     if((n==0&&m==0)&&(a==0&&k==0)) {
    //         break;
    //     }
    //     // n+mx = k+ay ---> (n-k) + mx = ay ---> (n-k) = (ay)%m for y in {1,2,3....}.  If (n-k)<0, Replace (n-k) += m
    //     // r + mx = ay.
    //     r = n - k;
    //     int ans = -1;
    //     while(r<0) { r += m; }
    //     int gcd = __gcd(a,m);
    //     if(r%gcd!=0) {
    //         cout << "Impossible" << endl;
    //         continue;
    //     }
    //     // r + mx = ay. gcd is known.
    //     for (int y=0; y<=m ; y++) {
    //         if((a*y)%m==r) {
    //             ans = y;
    //             break;
    //         }
    //     }
    //     if(ans==-1) {
    //         cout << "Impossible" << endl;
    //     }
    //     else {
    //         int temp = k + (a*ans);
    //         cout << temp << endl;
    //     }
    // }
    return 0;
}
