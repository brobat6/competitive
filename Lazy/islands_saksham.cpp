#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long

const int MAXN = 200100;
const int MOD = 1000000007;
vector <int> parent;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void make_set(int v) {
    parent[v] = v;
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    parent[b] = a;
}

void solve() {
    int m;
    int n;
    cin>>m>>n;
    parent.resize((m+1)*n+1);
    int arr[m+1][n+1];
    forn(i,1,m+1){
        forn(j,1,n+1){
            cin>>arr[i][j];
        }
    }
    forn(i,1,(m+1)*n+1){
        make_set(i);
    }
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    forn(i,1,m+1){
        forn(j,1,n+1){
            forn(k,0,4){
                if(arr[i][j]==1){
                    int x=i+dir[k][0];
                    int y=j+dir[k][1];
                    if(x < 1 || y < 1 || x >= m+1 || y >= n+1) continue;
                    if(arr[x][y] ==0) continue;
                    union_sets(i*n+j,x*n+y);
                }
            }
        }
    }
    int answer=0;
    forn(i,1,m+1){
        forn(j,1,n+1){
            if(arr[i][j]==1 && find_set(i*n+j)==(i*n+j)){
                answer++;
            }
        }
    }
    cout<<answer<<endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for(int I = 1; I <= 1; I++) {
        solve(); 
    }
    return 0;
}