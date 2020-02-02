/*
    Find max height of graph considering all nodes as root
*/
#include <iostream>
#include <vector>
#define MAXN 1000001
using namespace std;

vector<int> adj[MAXN];
int in[MAXN], out[MAXN];

void dfs_in(int u, int p) {
    in[u] = 0;
    for(auto v : adj[u]) {
        if(v != p) {
            dfs_in(v,u);
            in[u] = max(in[u], in[v]+1);
        }
    }
}

void dfs_out(int u, int p) {
    int max_ht_node=0, scnd_max_ht_node=0;
    for(auto v: adj[u]) {
        if(v != p) {
            if(in[v] > in[max_ht_node]) {
                scnd_max_ht_node = max_ht_node;
                max_ht_node = v;
            }
            else if(in[v] > in[scnd_max_ht_node])   scnd_max_ht_node = v;
        }
    }
    for(auto v: adj[u]) {
        if(v != p){
            int use_node = max_ht_node;
            if(v == max_ht_node)    use_node = scnd_max_ht_node;
            out[v] = max(in[use_node]+2, out[u]+1);
            dfs_out(v,u);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n-1; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs_in(1,0);
    dfs_out(1,0);
    for(int i=1; i<=n; i++) cout << max(in[i], out[i]) << endl;
    return 0;
}