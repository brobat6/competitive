// http://usaco.org/index.php?page=viewproblem2&cpid=595

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 1; i <= int(n); i++)
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    freopen("div7.in","r",stdin);
    freopen("div7.out","w",stdout);
    int n;
    cin >> n;
    int id[n+1];
    int temp;
    id[0] = 0;
    forn(i, n) {
        cin >> temp;
        id[i] = temp%7;
    }
    // id - [0,3,1,2,1,3,3,6].
    int sumid[n+1];
    sumid[0] = 0;
    forn(i, n) {
        sumid[i] = sumid[i-1] + id[i];
    }
    forn(i, n) {
        sumid[i] = sumid[i]%7;
    }
    map <int, set<int>> m;
    forn(i, n) {
        m[sumid[i]].insert(i);
    }
    int max = 0;
    for(int i=0; i<7; i++) {
        if(m[i].size()==0) continue;
        if(m[i].size()==1) {
            if(i==0) {
                temp = *--m[i].end();
            }
            else{
                continue;
            }
        }
        else {
            temp = (*--m[i].end())-(*m[i].begin());
        }
        if(temp > max) {
            max = temp;
        }
    }
    cout << max;
    return 0;
}
