#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define forn(i, n) for(int i = 0; i < n; i++)
#define fora(i, a, n) for(int i = a; i < n; i++)
#define pb push_back
#define vi vector<int>
const int N = (int)2e5 + 10;
const int M = (int)1e9 + 7;

pair<int,int> par[N][N];
// int size[N];
// int edge[N];
// int ma[N];
// int mi[N];

pair<int,int> find(pair<int,int> x)
{
    if(x==par[x.first][x.second]) return x;
    return par[x.first][x.second] = find(par[x.first][x.second]);
}

void unite(pair<int,int> a, pair<int,int> b)
{
    pair<int,int> c = find(a);
    pair<int,int> d = find(b);
    
    if(d!=c)
    {
        par[d.first][d.second]=c;
        
    }
}



int32_t main(void)
{
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
    {
        int a[m][n];
        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        forn(i, m)
        {
            forn(j, n)
            {
                cin >> a[i][j];
                par[i][j]={i,j};
            }
        }
        forn(i, m)
        {
            forn(j, n)
            {
                forn(k, 4)
                {
                    int x = i+dir[k][0];
                    int y = j+dir[k][1];
                    if(x<0 || y<0 || x>=m || y>=n)continue;
                    if(a[x][y]==1)
                    {
                        unite({i,j} , {x,y});
                        break;
                    }
                }
            }
        }
        int ans=0;
        forn(i, m)
        {
            forn(j, n)
            {
                if(par[i][j]=={i,j})ans++;
            }
        }
        cout << ans << endl;
    }
}