#include <bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
vector<int> parent;
int find(int x){
    if(x==parent[x]){
        return x;
    }
    return parent[x] = find(parent[x]);
}
bool unite(int x, int y){
    int a = find(x);
    int b = find(y);
    if(a!=b){
        parent[b] = a;
    }
    return false;
}
int32_t main() {
// The following two lines make input and output in C++ faster.
ios_base::sync_with_stdio(false);
cin.tie(0); cout.tie(0);
//int T = 0;
//cin >> T; // You can comment out this line when you don't need to take test cases as input.
//for(int t = 0; t < T; t++) {

//}
int m,n;
cin>>m>>n;
vector<vector<int>> vis(n+2);
parent.resize(n*m);
for (int i = 0; i < n*m; i++)
{
    parent[i]=i;
}

for (int i = 0; i < m+2; i++)
{
    vis[0].push_back(0);
    vis[n+1].push_back(0);
}
for (int i = 1; i < n+1; i++)
{
    vis[i].push_back(0);
    for (int j = 0; j < m; j++)
    {
        int x;
        cin>>x;
        if(x==1) 
            vis[i].push_back(1); 
        else vis[i].push_back(0);
    }
    vis[i].push_back(0);
}


for (int i = 1; i < n+1; i++)
{
    for (int j = 1; j < m+1; j++)
    {
        if(vis[i][j]){
        for (int k = 0; k < 4; k++)
        {
            int t = i+dir[k].first;
            int r = j+dir[k].second;
            if(vis[t][r]) unite(n*(t-1)+(r-1),n*(i-1)+(j-1));
        }
        }
    }
    
}

map<int,int> ans;
for (int i = 1; i < n+1; i++)
{
    for (int j = 1; j < m+1; j++)
    {
        if(vis[i][j]) ans[parent[n*(i-1)+(j-1)]]++;
    }
    
}
cout<<ans.size();

return 0;
}