// https://www.hackerearth.com/fr/practice/algorithms/graphs/articulation-points-and-bridges/practice-problems/algorithm/rhezo-and-destructive-mind/

#include <bits/stdc++.h>
using namespace std;

int arti[101], vis[101], f[101], l[101], timer;
std::vector<int> adj[101];

void dfs(int u, int par)
{
	vis[u] = 1;
	f[u] = l[u]= timer++;
	for(int i=0; i<adj[u].size(); i++)
	{
		int v = adj[u][i];
		if(!vis[v])
		{
			if(par == 0 && i == 1)
				arti[u] = 1;
			dfs(v,u);
			l[u] = min(l[u], l[v]);
			if(par != 0 && l[v] >= f[u])
				arti[u] = 1;
		}	
		else if(v != par)
			l[u]= min(l[u], f[v]);
	}
}

int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=0; i<m; i++)
	{
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}	
	for(int i=1; i<=n; i++)
		if(!vis[i])
			dfs(i,0);
	int q;
	cin >> q;
	while(q--)
	{
		int x;
		cin >> x;
		if(arti[x])
			cout << "Satisfied " << adj[x].size() << endl;
		else
			cout << "Not Satisfied\n";
	}	
	return 0;
}