#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, t;
    cin >> n >> t;
    vector<ll> h(n), c(n);
    rep(i,n) cin >> h[i];
    rep(i,n) cin >> c[i];

    ll ans = 0;
    rep(i,n){
        if(h[i] <= t) ans += c[i];
    }
    cout << ans << endl;

    return 0;
}