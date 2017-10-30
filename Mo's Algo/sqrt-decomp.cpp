/*
http://codeforces.com/contest/86/problem/D
*/

#include <iostream>
#include <math.h>
#include <algorithm>
#define BOOSTIO ios_base::sync_with_stdio (false), cin.tie (NULL) 
#define ll long long
#define MAXN 200001
using namespace std;

struct Query
{
	int l,r,idx;
}q[MAXN];

int n, quer, block_size; ll cnt[1000001]; 
ll ans[MAXN], ar[MAXN], curr_ans;

bool way(Query a, Query b) {
	if(a.l/block_size == b.l/block_size)
		return a.r < b.r;

	return a.l/block_size < b.l/block_size;
}

void add(int i) {
	curr_ans = curr_ans - (ll)(cnt[ar[i]]*cnt[ar[i]]*ar[i]);
	cnt[ar[i]]++;
	curr_ans = curr_ans + (ll)(cnt[ar[i]]*cnt[ar[i]]*ar[i]);	
}

void remove(int i) {
	curr_ans = curr_ans - (ll)(cnt[ar[i]]*cnt[ar[i]]*ar[i]);
	cnt[ar[i]]--;
	curr_ans = curr_ans + (ll)(cnt[ar[i]]*cnt[ar[i]]*ar[i]);	
}

void sqrt_decomposition() {

	block_size = sqrt(n);
	sort(q, q+quer, way);
	int L = 0, R= -1;

	for(int i=0; i<quer; i++) {
		while(L < q[i].l) {
			remove(L);
			L++;
		}
		while(L > q[i].l) {
			L--;
			add(L);
		}
		while(R < q[i].r) {
			R++;
			add(R);
		}
		while(R > q[i].r) {
			remove(R);
			R--;
		}
		ans[q[i].idx] = curr_ans;
	}
}

int main(int argc, char const *argv[])
{
	BOOSTIO;
	cin >> n >> quer;
	for(int i=0; i<n; i++)
		cin >> ar[i];
	for(int i=0; i<quer; i++) {
		cin >> q[i].l >> q[i].r;
		q[i].l--; q[i].r--;
		q[i].idx = i;
	}
	sqrt_decomposition();
	for(int i=0; i<quer; i++)
		cout << ans[i] << endl;
	return 0;
}