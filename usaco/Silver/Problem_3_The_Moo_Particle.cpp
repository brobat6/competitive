// http://usaco.org/index.php?page=viewproblem2&cpid=1040

#include <bits/stdc++.h>

#define MAXN 100001
#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int n, ans;
int parent[MAXN];
pair <int,int> p[MAXN];

int find(int x) {
    if(x==parent[x]) {
        return x;
    }
    else {
        return parent[x] = find(parent[x]);
    }
}

void unite(int a, int b) {
    int c = find(a);
    int d = find(b);
    if(c!=d) {
        parent[d] = c;
        ans--;
        // cout << "Unite!" << a << " " << b << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    freopen("moop.in","r",stdin);
    freopen("moop.out","w",stdout);
    cin >> n;
    ans = n;
    forn(j, n) parent[j] = j; 
    // ^^ Root of each set is the node itself.
    int temp1, temp2;
    forn(i, n) {
        cin >> temp1 >> temp2;
        p[i] = {temp1,temp2};
    }
    forn(i, n) {
        forn(j, n) {
            if(i==j) continue;
            if((p[i].first<=p[j].first)&&(p[i].second<=p[j].second)) {
                unite(i,j);
            }
        }
    }
    cout << ans;
    return 0;
}
