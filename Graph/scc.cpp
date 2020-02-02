// https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/practice-problems/algorithm/a-walk-to-remember-qualifier2/

#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mod 1000000007
using namespace std;

int n,m, ar[100001], vis[100001], vis2[100001];
std::vector<int> adj[100001], adj2[100001];
stack<int> st;

void toposort(int u)
{
	vis[u]=1;
	for(int i=0; i<adj[u].size(); i++) 
		if(!vis[adj[u][i]])
			toposort(adj[u][i]);
	st.push(u);
}

void transpose() 
{
	for(int i=1; i<=n; i++) 
		for(int j=0; j<adj[i].size(); j++)
			adj2[adj[i][j]].pb(i);
}

void dfs(int u)
{
	vis2[u]=1;
	for(int i=0; i<adj2[u].size(); i++) 
	{
		int v = adj2[u][i];
		if(!vis2[v])
		{
			ar[v]=ar[u]=1;
			dfs(v);
		}
	}		
}

int main()
{
	cin >> n >> m;
	for(int i=0; i<m; i++)	
	{
		int x,y;
		cin >> x >> y;
		adj[x].pb(y);
	}
	for(int i=1; i<=n; i++)
		if(!vis[i])
			toposort(i);

	transpose();

	while(!st.empty())
	{
		int t = st.top();
		st.pop();
		if(!vis2[t])
			dfs(t);
	}
	for(int i=1; i<=n; i++)
		cout << ar[i] << " ";
	cout << endl;
	return 0;
}