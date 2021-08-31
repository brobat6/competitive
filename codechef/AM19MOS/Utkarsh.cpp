#include <bits/stdc++.h>
using namespace std;

#define frr(i,a,b) for(int i=a;i<=b;i++)
#define test(t) int t; cin >> t; frr(tno,1,t)
#define endl '\n'
#define int long long

const int N=1000000007;
const int INF=1000000000000000;

int NMAX=100005;
int parent[100005]={};
int sz[100005]={};


int find_set(int v)
{
    if (v == parent[v])
    {
        return v;
    }
    parent[v] = find_set(parent[v]);
    return parent[v];
}

void make_set(int v)
{
    parent[v] = v;
    sz[v] = 1;
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}

void dfs(int sp,vector<vector<pair<int,int>>> &edge,int par[],int sizee[])
{
    for (int t1=0;t1<edge[sp].size();t1++)
    {
        int child=edge[sp][t1].second;
        int val=edge[sp][t1].first;
        if (par[child]==-2)
        {
            if (val<=sizee[sp])
            {
                par[child]=sp;
                union_sets(child,sp);
                dfs(child,edge,par,sizee);
            }
        }
    }
}

bool check(int sp1,int par[],vector<vector<int>> &adj,int n)
{
    int ck=0;
    for (int t1=0;t1<n;t1++)
    {
        int sp=t1;
        while (sp!=sp1)
        {
            sp=par[sp];
            if (adj[t1][sp]==0)
            {
                ck=1;
                break;
            }
        }
    }
    if (ck==1)
    {
        return false;
    }
    else
    {
        return true;
    }
}



signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    test(t)
    {
        int n,m;
        cin >> n >> m;
        vector<vector<pair<int,int>>> edge(n);
        vector<vector<int>> adj(n,vector<int>(n));
        for (int t1=0;t1<n;t1++)
        {
            for (int t2=0;t2<n;t2++)
            {
                adj[t1][t2]=0;
            }
        }
        for (int t1=0;t1<m;t1++)
        {
            int a,b;
            cin >> a >> b;
            edge[a-1].push_back(make_pair(0,b-1));
            edge[b-1].push_back(make_pair(0,a-1));
            adj[a-1][b-1]=1;
            adj[b-1][a-1]=1;
        }
        using pii=pair<int,int>;
        int sizee[n]={};
        int sp1=-1;
        for (int t1=0;t1<n;t1++)
        {
            sizee[t1]=edge[t1].size();
            if (sizee[t1]==(n-1))
            {
                sp1=t1;
            }
        }
        if (sp1==-1)
        {
            cout << "NO" << endl;
        }
        else
        {
            for (int t1=0;t1<n;t1++)
            {
                for (int t2=0;t2<edge[t1].size();t2++)
                {
                    int sp=edge[t1][t2].second;
                    edge[t1][t2].first=edge[sp].size();
                }
                sort(edge[t1].begin(),edge[t1].end(),greater<pair<int,int>>());
            }
            int par[n];
            fill(par,par+n,-2);
            for (int t1=0;t1<n;t1++)
            {
                make_set(t1);
            }
            par[sp1]=-1;
            dfs(sp1,edge,par,sizee);
            if (sz[find_set(0)]==n && check(sp1,par,adj,n))
            {
                cout << "YES" << endl;
                for (int t1=0;t1<n;t1++)
                {
                    cout << par[t1]+1 << " ";
                }
                cout << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}