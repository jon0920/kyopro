#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, k, m, x;
    cin >> n >> k >> m >> x;
    vector<ll> y(m);
    rep(i,m) cin >> y[i];

    rep(i,k){
        if(1 & x) break;
        x |= 1LL << n;
        x /= 2;
    }

    vector<ll> cnt(n);
    rep(i,n){
        if((x >> i) & 1) cnt[i]++;
    }

    rep(i,m){
        rep(j,n){
            if((y[i] >> j) & 1) cnt[j]++;
        }
    }

    ll ans = 0;
    for(int p = 1; p < n; p++){
        ll res = 0;
        rep(i,p) res += cnt[i] << i;
        for(int i = p; i < n; i++) res += cnt[i] << (i - p);
        ans = max(ans, res);
    }

    cout << ans << endl;
    
    return 0;
}