#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mod 1000000007
using namespace std;

int ar[100005];
int tree[300005]; //size is 3 times of ar

void build(int node, int start, int end)
{
	if(start == end)
	{
		tree[node] = ar[start];
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
void update(int node, int start, int end, int idx, int val)
{
	if(start == end)
	{
		tree[node] = val;
		ar[idx] = val;
	}
	else
	{
		int mid = (start+end)/2;
		if(start <= idx && idx <= mid)
		{
			update(2*node, start, mid, idx, val);
		}
		else
		{
			update(2*node+1, mid+1,end, idx, val);	
		}
		tree[node] = tree[2*node] + tree[2*node+1];
	}
}

// sum of range l to r
int query(int node, int start, int end, int l, int r)
{
	if(start > r || end < l)
	{
		return 0;
	}
	if(start >= l && end <= r)
	{
		return tree[node];
	}
	int mid = (start+end)/2;
	int p = query(2*node, start, mid, l, r);
	int q = query(2*node+1, mid+1, end, l, r);
	return (p+q);
}

int main()
{
	int n=10;
	build(1,1,n); // 1 based indexing of ar
	return 0;
}