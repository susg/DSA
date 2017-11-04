/*
https://www.codechef.com/problems/CHN16C
*/
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

ll gcd, x,y;

// Caluclate x,y for ax + by = gcd(a,b)
void extended_euclid(ll a, ll b) {
    if(b == 0) {
        gcd = a;
        x = 1;
        y = 0;
    }
    else {
        extended_euclid(b, a%b);
        ll temp = x;
        x = y;
        y = temp - (a/b)*y;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll a,n;
        cin >> a >> n;
        extended_euclid(a,n);
        if(gcd != 1)
            cout << -1 << endl;
        else {
            x = ((x%n)+n)%n;
            if(!x)
                x+=n;
            cout << x << endl;
        }
    }
    return 0;
}
