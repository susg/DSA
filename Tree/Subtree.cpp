/*
http://codeforces.com/contest/877/problem/E
*/

#include <bits/stdc++.h>
#define BOOSTIO ios_base::sync_with_stdio (false), cin.tie (NULL) 
#define ll long long 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mod 1000000007
#define MAXN 200001
using namespace std;

int n, ar[2*MAXN], t[MAXN], E[2*MAXN], L[2*MAXN], H[MAXN], F[MAXN], idx;
std::vector<int> graph[MAXN];

void update_E(int u, int l)
{
    idx++;
    E[idx] = u;
    F[u] = idx;
}

void dfs(int u, int l)
{
    update_E(u,l);
    H[u] = idx;
    
    for(int i=0; i<graph[u].size(); i++)
    {
        int v = graph[u][i];
        if(!H[v])
        {
            dfs(v,l+1);
        }
    }
    update_E(u,l);
    
}

int tree[6*MAXN], lazy[6*MAXN]; //size is 3 times of ar

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
    //cout << "node=> "<<node <<" " <<p <<" " << q << endl;
    return (p+q);
}

int main() {
    BOOSTIO;
    cin >> n;
    for(int i=2; i<=n; i++) {
        int x;
        cin >> x;
        graph[x].pb(i);
    }    
    for(int i=1; i<=n; i++)
        cin >> t[i];
    
    dfs(1,0);
    for(int i=1; i<=n; i++) {
        ar[H[i]] = ar[F[i]] = t[i];
    }
    build(1,1,2*n);
    //cout<<H[3]<<" "<<F[3]<<endl;
    int q;
    cin >> q;
    while(q--) {
        string type;
        int x;
        cin >> type >> x;
        if(type == "get") {
            cout << range_query(1,1,2*n,H[x],F[x])/2 << endl;
        }
        else {
            //cout<<H[x]<<" "<<F[x]<<endl;
            range_update(1,1,2*n,H[x],F[x]);
        }
    }
    return 0;
}