// https://codeforces.com/group/ajZVdc9MCh/contest/320153/problem/C

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; i++)
using namespace std;
#define MAXN 100100

long long v, e, m;
long long parent[MAXN];
long long num[MAXN];
long long t;

long long find(long long x) {
    if(x==parent[x]) return x;
    else return parent[x] = find(parent[x]);
}

void unite(long long a,long long b) {
    long long c = find(a);
    long long d = find(b);
    if(c!=d) {
        parent[d] = c;
        t += 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    cin >> v >> e >> m;
    forn(i, MAXN) num[i] = 0;
    forn(i, MAXN) parent[i] = i;
    long long a, b;
    t = 0;
    forn(i, e) {
        cin >> a >> b;
        --a; --b;
        unite(a,b);
    }
    // Extra cases :
    if(m==1) {
        cout << 0;
        return 0;
    }
    if(e==(v*(v-1)/2)) {
        cout << 0;
        return 0;
    }
    long long dummy[MAXN];
    forn(i, v) dummy[i] = find(i);
    long long xxx = 0; 
    forn(i, v-1) {
        if(dummy[i]!=dummy[i+1]) {
            xxx = 1;
        }
    }
    if(xxx==0) {
        cout << 1;
        return 0;
    }
    // x-x-x-x-x-x-x
    forn(i, v) {
        num[parent[i]] += 1;
    }
    long long n;
    if(v==(2+t)) n = 1;
    else if(v<(2+t)) n = 0;
    else {
        n = 1;
        for(int i=1; i<=(v-2-t); i++) {
            n *= v;
            n %= m;
        }
    }
    forn(i, v) {
        if(num[i]==0) continue;
        n *= num[i];
        n %= m;
    }
    cout << n;
    return 0;
}