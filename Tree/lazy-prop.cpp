/*
https://www.codechef.com/problems/FLIPCOIN
*/

#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mod 1000000007
using namespace std;

int tree[300005], lazy[300005]; //size is 3 times of ar

void build(int node, int start, int end)
{
	if(start == end)
	{
		tree[node] = 0;
	}
	else
	{
		int mid = (start+end)/2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = tree[2*node] + tree[2*node+1];
	}	
}

// update changes value ar[idx] to val
void range_update(int node, int start, int end, int l, int r)
{
	if(lazy[node])
	{
		tree[node] = end - start + 1 - tree[node];
		
		if(start != end)
		{
			lazy[2*node] ^= 1;
			lazy[2*node + 1] ^= 1;
		}
		
		lazy[node] = 0;
	}

	if(start > r || end < l)
		return;
	
	if(start >= l && end <= r)
	{
		tree[node] = end - start + 1 - tree[node];
		
		if(start != end)
		{
			lazy[2*node] ^= 1;
			lazy[2*node + 1] ^= 1;
		}
		return;
	}

	int mid = (start+end)/2;
	range_update(2*node, start, mid, l, r);
	range_update(2*node+1, mid+1, end, l, r);
	
	tree[node] = tree[2*node] + tree[2*node + 1];
}

// sum of range l to r
int range_query(int node, int start, int end, int l, int r)
{
	if(start > r || end < l)
	{
		return 0;
	}

	if(lazy[node])
	{
		tree[node] = end - start + 1 - tree[node];
		
		if(start != end)
		{
			lazy[2*node] ^= 1;
			lazy[2*node + 1] ^= 1;
		}
		
		lazy[node] = 0;
	}
	if(start >= l && end <= r)
	{
		return tree[node];
	}
	int mid = (start+end)/2;
	int p = range_query(2*node, start, mid, l, r);
	int q = range_query(2*node+1, mid+1, end, l, r);
	return (p+q);
}

int main() 
{
	int n,q;
	cin >> n >> q;
	build(1,1,n);
	while(q--) 
	{	
		int t,a,b;
		cin >> t >> a >> b;
		a++;b++;
		if(!t)
			range_update(1,1,n,a,b);
		else
			cout << range_query(1,1,n,a,b) << endl;
	}
	return 0;
}