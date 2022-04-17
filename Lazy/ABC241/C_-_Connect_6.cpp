#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    vector<vector<char>> v(n, vector<char>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    for(int i = 0; i < n - 5; i++) {
        for(int j = 0; j < n; j++) {
            int a = 0;
            for(int k = 0; k < 6; k++) {
                if(v[i + k][j] == '#') a++;
            }
            if(a >= 4) {
                cout << "Yes";
                return 0;
            }
        }
    }
    for(int i = 0; i < n - 5; i++) {
        for(int j = 0; j < n; j++) {
            int a = 0;
            for(int k = 0; k < 6; k++) {
                if(v[j][i + k] == '#') a++;
            }
            if(a >= 4) {
                cout << "Yes";
                return 0;
            }
        }
    }
    for(int i = 0; i < n - 5; i++) {
        for(int j = 0; j < n - 5; j++) {
            int a = 0;
            for(int k = 0; k < 6; k++) {
                if(v[j + k][i + k] == '#') a++;
            }
            if(a >= 4) {
                cout << "Yes";
                return 0;
            }
        }
    }
    for(int i = 5; i < n; i++) {
        for(int j = 0; j < n - 5; j++) {
            int a = 0;
            for(int k = 0; k < 6; k++) {
                if(v[i - k][j + k] == '#') a++;
            }
            if(a >= 4) {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
    
    return 0;
}