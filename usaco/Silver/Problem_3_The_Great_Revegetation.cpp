// http://www.usaco.org/index.php?page=viewproblem2&cpid=920

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 100000

int n, m;
int root[MAXN];
int ans;

int find(int x) {
    if(x==root[x]) return x;
    else return root[x] = find(root[x]);
}

int unite(int a, int b) {
    int c = find(a);
    int d = find(b);
    if(c!=d) {
        root[d] = c;
        ans--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("revegetate.in","r",stdin);
    // freopen("revegetate.out","w",stdout);
    cin >> n >> m;
    ans = n;
    char t1;
    int t2, t3;
    forn(i, n) root[i] = i;
    forn(i, m) {
        cin >> t1 >> t2 >> t3;
        --t2; --t3;
        unite(t2,t3);
    }
    cout << ans << endl;
    if(ans==0) {
        cout << "0";
        return 0;
    }
    cout << "1";
    forn(i, ans) cout << "0";
    // int binaryNum[32];
    // int i = 0;
    // while (ans > 0) {
        // binaryNum[i] = n%2;
        // n = n/2;
        // i++;
    // }
    // for (int j = i-1; j>=0; j--) cout << binaryNum[j];
    return 0;
}
