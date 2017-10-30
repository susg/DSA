#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define MAXN 100001
#define mod 1000000007
using namespace std;

struct Edge
{
	int to,from,wt;
}e[MAXN];

bool way_to_sort(Edge a, Edge b) {
	return a.wt < b.wt;
}

int par[MAXN], Rank[MAXN]; 

void makeSet(int i) {
	par[i] = i;
	Rank[i] = 0;
}

int find(int x){
	if(par[x] != x)
		par[x] = find(par[x]);
	return par[x];
}

void Link(int x, int y) {
	if(Rank[x] > Rank[y]) {
		par[y] = x;
	}
	else {
		par[x] = y;
		if(Rank[x] == Rank[y])
			Rank[y]++;
	}
}

void Union(int x, int y) {
	Link(find(x), find(y));
}

std::vector<pair<int, int> >  kruskal(int n, int m) {
	std::vector<pair<int, int> > MST;
	sort(e, e+m, way_to_sort);
	for(int i=1; i<=n; i++)
		makeSet(i);
	for(int i=0; i<m; i++) {
		if(find(e[i].to) != find(e[i].from)) {
			MST.pb(mp(e[i].to, e[i].from));
			Union(e[i].to, e[i].from);
		}
	}
	return MST;
}

int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		cin >> e[i].to >> e[i].from >> e[i].wt;	
	}	
	vector<pair <int, int> > A = kruskal(n,m);
	for(int i=0; i<A.size(); i++)
		cout << A[i].fi << " " << A[i].se << endl;
	return 0;
}