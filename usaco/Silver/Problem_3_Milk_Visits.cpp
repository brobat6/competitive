// http://usaco.org/index.php?page=viewproblem2&cpid=968

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
#define MAXN 100001

int n, m;
int root[MAXN];

int find(int x) {
    if(x==root[x]) return x;
    else return root[x] = find(root[x]);
}

void unite(int a, int b) {
    int c = find(a);
    int d = find(b);
    if(c!=d) {
        root[d] = c;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    freopen("milkvisits.in","r",stdin);
    freopen("milkvisits.out","w",stdout);
    char temp;
    cin >> n >> m;
    int arr[n];
    forn(i, n) {
        cin >> temp;
        if(temp=='G') arr[i]=1;
        else arr[i]=0;
    }
    // G = 1, H = 0
    forn(i, n) root[i] = i;
    int t1, t2, t3;
    forn(i, n-1) {
        cin >> t1 >> t2;
        --t1; --t2;
        if(arr[t1]==arr[t2]) unite(t1,t2);
    }
    forn(i, m) {
        cin >> t1 >> t2 >> temp;
        --t1; --t2;
        if(temp=='G') t3 = 1;
        else t3 = 0;
        if(find(t1)==find(t2)) {
            if(t3==arr[t1]) cout << "1";
            else cout << "0";
        }
        else {
            cout << "1";
        }
    }
    return 0;
}
