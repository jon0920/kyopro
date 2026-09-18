#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n), t(n);
    rep(i,n) cin >> a[i] >> t[i];
    vector<ll> imos(n + 1);
    rep(i,q){
        ll l, r, x;
        cin >> l >> r >> x;
        l--;
        imos[l] += x;
        imos[r] -= x;
    }
    rep(i,n) imos[i + 1] += imos[i];

    int ans = 0;
    rep(i,n){
        if(imos[i] + a[i] >= t[i]) ans++;
    }
    cout << ans << endl;
    
    return 0;
}