// http://www.spoj.com/problems/LCA/

#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mod 1000000007
#define MAXN 1001
using namespace std;

std::vector<int> adjList[MAXN];
int n, ar[2*MAXN], t[MAXN], E[2*MAXN], L[2*MAXN], H[MAXN], idx;

int tree[6*MAXN];

void build(int node, int start, int end)
{
	if(start == end)
	{
		tree[node] = start;
	}
	else
	{
		int mid = (start+end)/2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		
		if (L[tree[2*node]] < L[tree[2*node+1]])
			tree[node] = tree[2*node];
		else
			tree[node] = tree[2*node + 1];
	}	
}

int query(int node, int start, int end, int l, int r)
{
	if(start > r || end < l)
	{
		return -1;
	}
	if(start >= l && end <= r)
	{
		return tree[node];
	}

	int mid = (start+end)/2;
	int p = query(2*node, start, mid, l, r);
	int q = query(2*node+1, mid+1, end, l, r);
	if(p == -1)
		return q;
	else if(q == -1)
		return p;
	else if(L[p] < L[q])
		return p;
	else
		return q;
}

void update_E(int u, int l)
{
    idx++;
    E[idx] = u;
    L[idx] = l;
}

void dfs(int u, int l)
{
    update_E(u,l);
    H[u] = idx;
    
    for(auto v : adjList[u])
    {
        if(!H[v])
        {
            dfs(v,l+1);
            update_E(u,l);
        }
    }  
}

int lca(int x, int y)
{
	int l = H[x];
	int r = H[y];
	if(l>r)
		swap(l,r);
	return E[query(1,1,idx,l,r)];
}

void ini()
{
	idx = 0;
	for(int i=0; i< 2*MAXN; i++)
		E[i] = L[i] = 0;
	for(int i=0; i< MAXN; i++)
	{
		H[i] = 0;
		adjList[i].clear();
	}	
}

int main()
{
	int t;
	scanf("%d", &t);
	for(int kk=1; kk<=t; kk++)
	{
		ini();
		int n;
		scanf("%d", &n);
		for(int i=1; i<=n; i++)
		{
			int m;
			scanf("%d", &m);
			while(m--)
			{
				int x;
				scanf("%d", &x);
				adjList[i].pb(x);
				adjList[x].pb(i);
			}
		}
		dfs(1,0);
		build(1,1,idx);
		int q;
		scanf("%d", &q);
		printf("Case %d:\n", kk);
		while(q--)
		{
			int x,y;
			scanf("%d%d", &x, &y);
			printf("%d\n", lca(x,y));
		}
	}
	return 0;
}