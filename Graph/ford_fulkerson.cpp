#include <bits/stdc++.h>
#define MAXN 101
using namespace std;

/*
	v -> no. of vertices
	e -> no. of edges
	s -> source
	t -> sink
	graph[][] -> original graph
	res_graph -> residual graph
*/	

int v,e,s,t, graph[MAXN][MAXN], res_graph[MAXN][MAXN];

// BFS to check if there is augmenting path from s to t in res_graph[][]
bool bfs(int parent[])
{
	bool flag = false;
	int visit[MAXN];
	memset(visit, 0, sizeof(visit));
	parent[s] = -1;
	queue<int> q;
	q.push(s);
	visit[s] = 1;
	
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		if(u == t)
			flag = true;
		for(int i=1; i<=v; i++)
		{
			if(res_graph[u][i] && !visit[i])
			{
				parent[i] = u;
				visit[i] = 1;
				q.push(i);
			}
		}
	}
	return flag;
}

// Finding max flow using ford fulkerson algorithm
int max_flow()
{
	int parent[MAXN], flow=0;
	
	// Create initial res_graph[][]
	for(int i=1; i<=v; i++)
		for(int j=1; j<=v; j++)
			res_graph[i][j] = graph[i][j];

	while(bfs(parent))
	{
		int path_flow = INT_MAX;
		
		// Find the min path flow in augmenting path
		for(int u = t; u != s; u = parent[u])
		{
			int x = parent[u];
			path_flow = min(path_flow, res_graph[x][u]);
		}
		
		// Update the residual graph
		for(int u = t; u != s; u = parent[u])
		{
			int x = parent[u];
			res_graph[x][u] -= path_flow;
			res_graph[u][x] += path_flow;
		}
		flow += path_flow;
	}
	// Return max flow
	return flow;
}

int main()
{
	// Taking Input
	cin >> v >> e;
	for(int i=1; i<=e; i++)
	{
		int x,y,c;
		cin >> x >> y >> c;
		graph[x][y] = c;
	}
	cin >> s >> t;
	
	// Output the Max Flow
	cout << max_flow() << endl;

	return 0;
}