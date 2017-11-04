#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;

ll INF =100000000007;
std::vector< pair<int, ll> > graph[100005];

ll djikstra(int source, int n)
{
	priority_queue< pair<ll, int>, vector< pair<ll, int> >, greater< pair< ll, int> > > visited;
	visited.push(mp(0ll,source));

	ll dist[n+1];
	memset(dist, INF, sizeof(dist));
	dist[source] = 0;

	while(!visited.empty())
	{
		int u = visited.top().se;
		
		visited.pop();

		for(int i = 0;  i < graph[u].size(); i++)
		{
			int v = graph[u][i].fi;
			ll weight = graph[u][i].se;
			if( dist[u] + weight < dist[v] )
			{
				dist[v] = dist[u] + weight;
				visited.push(mp(dist[v], v));
			}	
		}
	}
	dist[n] = dist[n] == INF ? -1 : dist[n];
	return dist[n];
}

int main()
{
	int vertices, edges;
	cin >> vertices >> edges;
	for(int i=0; i<edges; i++)
	{
		int u,v;
		ll weight;
		cin >> u >> v >> weight;
		graph[u].pb(mp(v, weight));
		graph[v].pb(mp(u, weight));
	}
	cout << djikstra(1, vertices) << endl;;

	return 0;
}
