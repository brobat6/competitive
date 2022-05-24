#include <bits/stdc++.h>
using namespace std;
#define int long long

// cout << setprecision(15) << ...;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    double eps = 1e-7;
    double l = 0.0;
    double r = 2e7;
    double ans = 0.0;
    while((r - l) > eps) {
        double m = (l + r)/2;
        
        bool check;
        // make changes here.
 
        if(check) {
            ans = m;
            l = m + eps;
        } else {
            r = m - eps;
        }
    }
    
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long

// bool is_subsequence(string s, string t) {
//     // return true if S is a subsequence of T, otherwise false.
//     int n = s.length();
//     int m = t.length();
//     int j = 0;
//     for(int i = 0; i < n; i++) {
//         if(s[i] == t[j]) {
//             j++;
//         }
//         if(j == m) break;
//     }
//     return (j == m);
// }

// int32_t main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     string s;
//     string t;
//     cin >> s >> t;

    
//     return 0;
// }