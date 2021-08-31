#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (long long i = 0; i < n; i++)
#define ll long long
#define MAXN 200100
#define MOD 1000000007

ll r, n, m;
ll t1, t2, t3, t4;
struct Matrix {
    int a;
    int b;
    int c;
    int d;
};
Matrix arr[MAXN];
Matrix st[4*MAXN];
Matrix identity {1, 0, 0, 1};

Matrix combine(Matrix A, Matrix B) {
    // C = AB
    Matrix C;
    C.a = (A.a*B.a + A.b*B.c)%r;
    C.b = (A.a*B.b + A.b*B.d)%r;
    C.c = (A.c*B.a + A.d*B.c)%r;
    C.d = (A.c*B.b + A.d*B.d)%r;
    return C;
}

void build(int v, int tl, int tr) {
    if(tl==tr) st[v] = combine(arr[tl], identity);
    else {
        int tm = (tl + tr)/2;
        build(v*2, tl, tm);
        build(v*2 + 1, tm + 1, tr);
        st[v] = combine(st[v*2], st[v*2+1]);
    }
}

Matrix query(int v, int tl, int tr, int l, int r) {
    if(l > r) return identity;
    if(l==tl && r==tr) return st[v];
    int tm = (tl + tr)/2;
    return combine(query(v*2, tl, tm, l, min(r, tm)), query(v*2 + 1, tm + 1, tr, max(l, tm+1), r));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // int t; cin >> t; while(t--)
{
    // Code goes here
    cin >> r >> n >> m;
    forn(i, n) cin >> arr[i].a >> arr[i].b >> arr[i].c >> arr[i].d;
    build(1, 0, n-1);
    forn(i, m) {
        cin >> t1 >> t2;
        Matrix A = query(1, 0, n-1, t1-1, t2-1);
        printf("%d %d\n%d %d\n\n", A.a, A.b, A.c, A.d);
    }
}
    return 0;
}