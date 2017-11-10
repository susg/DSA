/*
http://codeforces.com/contest/888/problem/E
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll X[300005], Y[300005];
   
void calcsubarray(ll a[], ll x[], int n, int c, ll m)
{
    for (int i=0; i<(1<<n); i++)
    {
        ll s = 0;
        for (int j=0; j<n; j++)
            if (i & (1<<j))
                s = (s + a[j+c]) % m;
        x[i] = s;
    }
}
 
ll meet_in_the_middle(ll a[], int n, ll m)
{
    calcsubarray(a, X, n/2, 0, m);
    calcsubarray(a, Y, n-n/2, n/2, m);
 
    int size_X = 1<<(n/2);
    int size_Y = 1<<(n-n/2);

    ll ans = 0;

    sort(Y, Y+size_Y);
 
    for (int i=0; i<size_X; i++)
    {
        int p = lower_bound(Y, Y+size_Y, m-X[i]-1) - Y;

        if (p == size_Y || Y[p] != (m-X[i]-1))
            p--;

        ans = max(ans, Y[p] + X[i]);
    }

    return ans;
}    
 
int main()
{
    int n;
    ll m, ar[40];
    cin >> n >> m;
    
    for(int i=0; i<n; i++)
    {
        cin >> ar[i];
        ar[i] %= m;
    }
    
    cout << meet_in_the_middle(ar, n, m) << endl;

    return 0;
}