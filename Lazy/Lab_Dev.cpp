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


vector<char> v[1005][1005];
int vis[1005][1005];
queue<pair<int, int>> q;
vector<pair<int, int>> adj[1005][1005];
int st1, st2, en1, en2;

void bfs(int x, int y)
{
    vis[x][y]=1;
    q.push({x, y});
    while(!q.empty())
    {
        auto curr = q.front();
        q.pop();
        for(auto next : adj[curr.first][curr.second])
        {
            if(vis[next.first][next.second]) continue;
            q.push(next);
            vis[next.first][next.second]=1;

            if(next.first == curr.first+1)
            {
                v[next.first][next.second] = v[curr.first][curr.second];   
                v[next.first][next.second].pb('D');
            }
            else if(next.first == curr.first-1)
            {
                v[next.first][next.second] = v[curr.first][curr.second];
                v[next.first][next.second].pb('U');
            }
            else if(next.second == curr.second+1)
            {
                v[next.first][next.second] = v[curr.first][curr.second];
                v[next.first][next.second].pb('R');
            }
            else if(next.second == curr.second-1)
            {
                v[next.first][next.second] = v[curr.first][curr.second];
                v[next.first][next.second].pb('L');
            }

            if(next.first==en1 && next.second==en2)
            {
                return;
            }
            
        }
    }
}

int32_t main(void)
{
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        char a[n+1][m+1];
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                cin >> a[i][j];
                if(a[i][j]=='A')
                {
                    st1=i;
                    st2=j;
                }
                if(a[i][j]=='B')
                {
                    en1=i;
                    en2=j;
                }
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(i>=2 && a[i-1][j]!='#')
                {
                    adj[i][j].pb({i-1, j});
                }
                if(i<=n-1 && a[i+1][j]!='#')
                {
                    adj[i][j].pb({i+1, j});
                }
                if(j>=2 && a[i][j-1]!='#')
                {
                    adj[i][j].pb({i, j-1});
                }
                if(j<=m-1 && a[i][j+1]!='#')
                {
                    adj[i][j].pb({i, j+1});
                }
            }
        }
        bfs(st1, st2);
        if(vis[en1][en2]==0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            // cout << v[en1][en2].size() << endl;
            // for(auto i : v[en1][en2])
            // {
            //     cout << i;
            // }
            // cout << endl;
        }
    }
}