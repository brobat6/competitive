#include <bits/stdc++.h>
using namespace std;
#define int long long

int t = 0;

void f(int n) {
    t++;
    if(n <= 1) return;
    f(n - 1);
    f(n / 2);
}


const int N = (int)1E2 + 5;
int spf[N + 1];

void find_spf() {
    for(int i = 0; i <= N; i++) {
        spf[i] = i;
    }
    for(int i = 2; i <= N; i++) {
        if(spf[i] == i) {
            for(int j = i * i; j <= N; j += i) {
                if(spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
    for(int i = 2; i <= N; i++) {
        cout << i << " " << spf[i] << " ; ";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for(int i = 1; i <= 50; i++) {
        t = 0;
        f(i);
        cout << "(" << i << "," << t << ")\n"; 
    }
    find_spf();
    
    return 0;
}