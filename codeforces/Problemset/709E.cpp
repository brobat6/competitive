// NOT MY CODE. 
// LINK - https://codeforces.com/contest/709/submission/55608451
// only comments are mine.

#include <iostream>
#include <vector>
using namespace std;
int n,c,par[400005],sz[400005],dp[400005];
vector<int> v[400005];
int pre(int node,int p)
{
	par[node]=p;
	sz[node]=1;
	for (int u:v[node])
	{
		if (u!=p)
		sz[node]+=pre(u,node);
	}
	return sz[node];
}
int find(int node,int p)
{
	for (int u:v[node])
	{
		if (u!=p && sz[u]>n/2)
		return find(u,node);
	}
	return node;
}
void dfs(int node,int p)
{
	if (p!=c)
	dp[node]=dp[p];
	if (n-sz[p]<=n/2)
	dp[node]=max(dp[node],n-sz[p]);
	for (int u:v[node])
	{
		if (u!=p)
		dfs(u,node);
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	// Choose an arbitrary vertex and calculate sizes from it.
	pre(1,0); 
	// Find a centroid of the tree (there exists a centroid in every tree).
	c=find(1,0);
	// Calculate the sizes assuming the centroid is the root.
	// sz[i] = 1 + sum(sz[j]), where j is the set of children of i.
	pre(c,0);
	// mx.first stores the child of c with highest sz, mx.second stores the second highest sz child.
	pair<int,int> mx(-1,-1);
	for (int u:v[c])
	{
		if (mx.first==-1 || sz[u]>sz[mx.first])
		{
			mx.second=mx.first;
			mx.first=u;
		}
		else if (mx.second==-1 || sz[u]>sz[mx.second])
		mx.second=u;
	}
	for (int u:v[c])
	{
		if (u==mx.first && mx.second!=-1)
		dp[u]=sz[mx.second];
		if (u!=mx.first)
		dp[u]=sz[mx.first];
		dfs(u,c);
	}
	// c is always correct.
	// For a node i, the component with biggest size to it has size n - sz[i] (the component going UPWARD in the tree)
	// dp[i] stores the amount of size (between 1 and n/2) that can be cut from this highest component.
	for (int i=1;i<=n;i++)
	{
		if (i==c || n-sz[i]-dp[i]<=n/2)
		printf("1 ");
		else
		printf("0 ");
	}
}
