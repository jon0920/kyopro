#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<ll> p(n), q(n);
    rep(i,n) cin >> p[i] >> q[i];
    ll a = p[0], b = q[0];
    for(int i = 1; i < n; i++){
        a = lcm(a, p[i]);
        b = gcd(b, q[i]);
    }

    while(gcd(a, b) != 1){
        ll d = gcd(a, b);
        a /= d; b /= d;
    }

    cout << a << " " << b << endl;

    return 0;
}