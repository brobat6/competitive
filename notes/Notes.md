<a name='0'></a>

# TABLE OF CONTENTS

- [1 - Matrix Exponentiation](#1)
- [2 - Convex Hull Trick - Resources](#2)

<a name='1'></a>

# Matrix Exponentiation

### Problems

1. [Atcoder - R - Walk](https://atcoder.jp/contests/dp/tasks/dp_r)
2. [Codeforces - E. Product Oriented Recurrence](https://codeforces.com/contest/1182/problem/E)
3. [DMOJ - Fibonacci Sequence (Harder)](https://dmoj.ca/problem/fibonacci2)

**Solution - DMOJ - Fibonacci Sequence (Harder)**

```c++
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 200100
#define MOD 1000000007

string n;
vector<vector<int>> ans(2, vector<int>(2));
vector<vector<int>> T(2, vector<int>(2)); // Stores the current power of 10
vector<vector<int>> X(2, vector<int>(2)); 

void multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
    vector<vector<int>> prod(2, vector<int>(2));
    forn(i, 0, 2) forn(j, 0, 2) prod[i][j] = 0;
    forn(i, 0, 2) forn(j, 0, 2) forn(k, 0, 2) {
        prod[i][j] = (prod[i][j] + A[i][k]*B[k][j]) % MOD;
    }
    forn(i, 0, 2) forn(j, 0, 2) A[i][j] = prod[i][j];
}

void power(vector<vector<int>> &A, int b) {
    vector<vector<int>> prod(2, vector<int>(2));
    prod[0][0] = prod[1][1] = 1; prod[0][1] = prod[1][0] = 0;
    while (b > 0) {
        if(b & 1) multiply(prod, A);
        multiply(A, A);
        b >>= 1;
    }
    forn(i, 0, 2) forn(j, 0, 2) A[i][j] = prod[i][j];
}

void func(int p) {
    // 1. Raise matrix X to the power P, then do ans = ans * X
    // 2. Raise matrix T to the power 10
    // 3. Make matrix X = matrix T
    power(X, p);
    multiply(ans, X);
    power(T, 10);
    forn(i, 0, 2) forn(j, 0, 2) X[i][j] = T[i][j];
}

void assign(vector<vector<int>> &A) {
    A[0][0] = 0;
    A[0][1] = A[1][0] = A[1][1] = 1;
}

void solve() {
    assign(ans); assign(X); assign(T);
    cin >> n;
    int x = n.length();
    for(int i = x - 1; i>=0; i--) func(n[i] - '0');
    cout << ans[0][0];
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}
```

<a name='2'></a>

# Convex Hull Trick - Resources

https://codeforces.com/blog/entry/63823

https://cp-algorithms.com/geometry/convex_hull_trick.html

http://web.archive.org/web/20181030143808/http://wcipeg.com/wiki/Convex_hull_trick

https://atcoder.jp/contests/dp/tasks/dp_z

https://www.youtube.com/watch?v=FAQxdm0bTaw

