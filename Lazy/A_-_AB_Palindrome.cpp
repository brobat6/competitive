#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < n/2; i++) {
        if(s[i] == s[n - i - 1]) continue;
        if(s[i] == 'A') {
            if(i > 0 && s[i - 1] == 'A') {
                s[i - 1] = 'A';
                s[i] = 'B';
            } else if(i > 0 && s[n - i] == 'B') {
                s[n - i - 1] = 'A';
                s[n - i] = 'B';
            }
        } else {
            if(s[i + 1] == s[n - i - 2]) {
                if(s[i + 1] == 'A') {
                    s[n - i - 1] = 'B';
                } else {
                    s[i] = 'A';
                }
            } else {
                if(s[i + 1] == 'A') {
                    s[i] = 'A';
                    s[i + 1] = 'B';
                } else {
                    s[i] = 'A';
                }
            }
        }
    }
    for(int i = 0; i < n/2; i++) {
        if(s[i] == s[n - i - 1]) continue;
        if(s[i] == 'A') {
            if(i > 0 && s[i - 1] == 'A') {
                s[i - 1] = 'A';
                s[i] = 'B';
            } else if(i > 0 && s[n - i] == 'B') {
                s[n - i - 1] = 'A';
                s[n - i] = 'B';
            }
        } else {
            if(s[i + 1] == s[n - i - 2]) {
                if(s[i + 1] == 'A') {
                    s[n - i - 1] = 'B';
                } else {
                    s[i] = 'A';
                }
            } else {
                if(s[i + 1] == 'A') {
                    s[i] = 'A';
                    s[i + 1] = 'B';
                } else {
                    s[i] = 'A';
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(s[i] != s[n - i - 1]) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    
    return 0;
}