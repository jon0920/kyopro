#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, m, s;
    cin >> n >> m >> s;
    vector<ll> p(n);
    rep(i,n) cin >> p[i];
    rep(i,m){
        ll t, q;
        cin >> t >> q;
        t--;
        ll x = p[t] * q;
        s += x - x / 2;
    }
    cout << s << endl;

    return 0;
}