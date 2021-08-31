// https://codeforces.com/problemset/problem/162/C

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;

int n;
vector <int> v;

void prime() {
    for(int i=2; i<=pow(n,0.5); i++) {
        while(n%i==0) {
            n /= i;
            v.push_back(i);
        }
    }
    v.push_back(n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);

    cin >> n;
    prime();
    int s = v.size();
    if(v[s-1]==1) s-=1;
    forn(i, s-1) cout << v[i] << "*";
    cout << v[s-1];

    return 0;
}
