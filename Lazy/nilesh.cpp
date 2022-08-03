#include <bits/stdc++.h>
using namespace std;
#define int long long

// int solution(string &s) {
//     int n = s.length();
//     set <char> t;
//     int ans = 1;
//     for(int i = 0; i < n; i++) {
//         if(t.find(s[i]) == t.end()) {
//             t.insert(s[i]);
//         } else {
//             t.clear();
//             t.insert(s[i]);
//             ans++;
//         }
//     }
//     return ans;
// }

int solution(vector <int> &A, int S) {
    int n = A.size();
    map<long long, long long> m;
    long long x = 0;
    m[x]++;
    for(int i = 0; i < n; i++) {
        A[i] -= S;
        x += A[i];
        m[x]++;
    }
    long long ans = 0;
    for(auto i : m) {
        ans += (i.second) * (i.second - 1) / 2;
    }
    int a;
    if(ans > (int)1E9) a = (int)1E9;
    else a = ans;
    return a;
}

string solution(string &s) {
    vector <int> cnt(10, 0);
    for(auto i : s) {
        cnt[i - '0']++;
    }
    int odd = -1;
    string ans;
    for(int i = 9; i >= 0; i--) {
        if(i == 0 && (int)ans.length() == 0) {
            continue;
        }
        for(int j = 0; j < cnt[i] / 2; j++) {
            ans += '0' + i;
        }
        if(odd == -1 && cnt[i] % 2 == 1) {
            odd = i;
        }
    }
    int m = ans.size();
    if(odd != -1) {
        ans += '0' + odd;
    }
    for(int i = m - 1; i >= 0; i--) {
        ans += ans[i];
    }
    if((int)ans.size() == 0) return "0";
    return ans;
}

int solution(vector <string> &A) {
    int n = A.size();
    sort(A.begin(), A.end());
    
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // string s;
    // cin >> s;
    // cout << solution(s);

    // int n = (int)1E6;
    // cin >> n;
    // vector <int> v(n);
    // for(int i = 0; i < n; i++) {
    //     // cin >> v[i];
    //     v[i] = (i % 2 ? 1 : -1);
    // }
    // int s = 0;
    // // cin >> s;
    // cout << solution(v, s);

    string s;
    cin >> s;
    cout << solution(s);
    
    return 0;
}