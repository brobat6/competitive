#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define forn(i, n) for(int i = 0; i < n; i++)
#define fora(i, a, n) for(int i = a; i < n; i++)
#define pb push_back
#define vi vector<int>
const int N = (int)3e5 + 10;
const int M = (int)1e9 + 7;

int par[N];
int sz[N];
int ma[N];
int mi[N];

int find(int x)
{
    if(x==par[x]) return x;
    return par[x] = find(par[x]);
}

void unite(int a, int b)
{
    int c = find(a);
    int d = find(b);
    if(d!=c)
    {
        par[d]=c;
        sz[c]+=sz[d];
        ma[c]=max(ma[c], ma[d]);
        mi[c]=min(mi[c], mi[d]);
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
        forn(i, n)
        {
            par[i]=i;
            sz[i]=1;
            ma[i]=i;
            mi[i]=i;
        }
        forn(i, m)
        {
            string s;
            cin >> s;
            if(s=="union")
            {
                int a, b;
                cin >> a >> b;
                a--;
                b--;
                unite(a, b);
            }
            else
            {
                int a;
                cin >> a;   
                a--;
                // cout << "x";
                int y = find(a);
                cout << mi[y] + 1 << " " << ma[y] + 1 << " " << sz[y] << endl;
            }
        }
    }
}