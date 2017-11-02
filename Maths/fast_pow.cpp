/*
http://www.spoj.com/problems/ZSUM/
*/

#include <cstdio>
#define ll long long
#define mod 10000007
using namespace std;

// Compute x^y % mod in logn
ll fpow(ll x, ll y) {
    ll ans =1;
    while(y) {
        if(y%2)
            ans = (ans*x) % mod;
        x = (x*x) % mod;
        y = y >> 1;
    }
    return ans;
}

int main() {
    ll n,k;
    while(1)
    {
        scanf("%lld%lld",&n,&k);
        if(n==0 && k==0 )
            return 0;
        else {
            ll s1, s2,s3,s4;
            s1 = (2 * fpow(n-1,n-1) ) % mod;
            s2 = (2 * fpow(n-1,k) ) % mod;
            s3 = fpow(n,k);
            s4 = fpow(n,n);
            ll res = (s1 + s2 +s3 + s4) % mod;
            printf("%lld\n",res);
        }
    }
}
