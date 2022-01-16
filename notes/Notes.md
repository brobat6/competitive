# TABLE OF CONTENTS

- [TABLE OF CONTENTS](#table-of-contents)
- [Matrix Exponentiation](#matrix-exponentiation)
    - [Problems](#problems)
- [Convex Hull Trick - Resources](#convex-hull-trick---resources)
- [Topological Sort - BFS](#topological-sort---bfs)
- [Accurate floor/ceil function](#accurate-floorceil-function)
- [Installing C++ Compiler for Windows](#installing-c-compiler-for-windows)
- [Resources - Books](#resources---books)
- [Bit Manipulation & Bitwise Operations](#bit-manipulation--bitwise-operations)

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

<a name='3'></a>

# Topological Sort - BFS

- **int needed[MAXN];** the number of nodes needed as pre-requisites before you can traverse the current node.
- **int done[MAXN]; ** the number of pre-requisite nodes that have been completed.
- Whenever done[i] becomes equal to needed[i], push it into the queue because it is ready to be traversed now.
- Starting vertices are those which have needed[i] = 0. EZ!



https://www.spoj.com/problems/TOPOSORT/

```c++
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 10100;
const int MOD = 1000000007;

int n, m, t1, t2;
vector <int> f[MAXN], needed, done, v;
int dist[MAXN];

void bfs() {
    memset(dist, -1, sizeof(dist));
    priority_queue <int, vector<int>, greater<int>> q;
    forn(i, 0, n) {
        if(needed[i]==0) {
            q.push(i);
            dist[i] = 0;
        }
    }
    while(!q.empty()) {
        int curr = q.top();
        v.push_back(curr);
        q.pop();
        for(auto next : f[curr]) {
            if(dist[next] == -1) {
                done[next]++;
                if(done[next]==needed[next]) {
                    dist[next] = dist[curr] + 1;
                    q.push(next);
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    needed.resize(n, 0); done.resize(n, 0);
    forn(i, 0, m) {
        cin >> t1 >> t2;
        --t1; --t2;
        f[t1].push_back(t2);
        needed[t2]++;
    }
    bfs();
    bool pos = true;
    forn(i, 0, n) if(dist[i]==-1) pos = false;
    if(pos) for(auto i : v) cout << i + 1 << " ";
    else cout << "Sandro fails.";
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}
```

https://codeforces.com/problemset/problem/510/C

```c++
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

int n;
vector <string> v;
vector <int> adj[26];
int needed[26], done[26], dist[26];
vector <int> ans;
bool pos;

pair<char, char> compare(string &a, string &b) {
    forn(i, 0, min(a.length(), b.length())) {
        if(a[i]!=b[i]) return {a[i], b[i]};
    }
    if(a.length() > b.length()) pos = false;
    return {a[0], b[0]};
}

void bfs() {
    memset(dist, -1, sizeof(dist));
    queue <int> q;
    forn(i, 0, 26) {
        if(needed[i]==0) {
            q.push(i);
            dist[i] = 0;
        }
    }
    while(!q.empty()) {
        int curr = q.front();
        ans.push_back(curr);
        q.pop();
        for(auto next : adj[curr]) {
            done[next]++;
            if(done[next]==needed[next]) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }
}

void solve() {
    cin >> n;
    pos = true;
    forn(i, 0, 26) {
        needed[i] = 0;
        done[i] = 0;
    }
    v.resize(n);
    forn(i, 0, n) cin >> v[i];
    forn(i, 0, n - 1) {
        auto x = compare(v[i], v[i + 1]);
        if(x.first==x.second) continue;
        // cout << x.first << " " << x.second << endl;
        adj[x.first - 'a'].push_back(x.second - 'a');
        needed[x.second - 'a']++;
    }
    bfs();
    forn(i, 0, 26) if(dist[i]==-1) pos = false;
    if(pos) for(auto i : ans) cout << (char)('a' + i);
    else cout << "Impossible";
    
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}
```

<a name='4'></a>

# Accurate floor/ceil function

Suppose we want to find the smallest integer satisfying the inequality 
$$
x <= a/b
$$
So we will need to calculate the floor of b/a (or ceil for >=). But floating point isn't that accurate and we may end up with a wrong value. A way to do it without using double is:

```c++
int accurateFloor(int a, int b) {
    int val = a/b;
    while(val * b > a) val--;
    return val;
}

int accurateCeil(int a, int b) {
    int val = a/b;
    while(val * b < a) val++;
    return val;
}
```







# Installing C++ Compiler for Windows

Follow the steps from https://www.msys2.org/.


Download the installer.

Install MSYS2 in C:\msys64

Open MSYS2 from Start, it will open a terminal. Run the following commands -
1. pacman -Syu
2. pacman -Su
3. pacman -S mingw-w64-x86_64-toolchain

Add C:\msys64\mingw64\bin to PATH (search Environment Variables on Start to open)

Check if mingw is installed or not by typing "g++ --version" and "gdb --version" in the command prompt.

Helpful resources -
- https://code.visualstudio.com/docs/cpp/config-mingw
- https://www.msys2.org/
- https://www.devdungeon.com/content/install-gcc-compiler-windows-msys2-cc


# Resources - Books

Books I've found extremely useful so far - 
- An Introduction to the USA Computing Olympiad [Darren Yao]
- Competitive Programmer's Handbook [CSES]

This second list doesn't refer to "recommended" books or anything, just books I've discovered that might be useful someday.
 - Effective Modern C++ [Scott Meyers]

# Bit Manipulation & Bitwise Operations

Easily get the i^th bit of n in binary - 
```c++
int b = (n>>(30 - i)) & 1; 
// Assuming 30 is the total number of bits in decimal representation of n (Works for n <= 10^9).
```
