#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 4e18;

pair<ll,ll> op(pair<ll,ll> a, pair<ll,ll> b){
    return {a.first + b.first, min(a.second, b.second)};
}

pair<ll,ll> e(){ return {0, INF}; }

int main(){

    ll n, w, k;
    cin >> n >> w >> k;
    vector<pair<ll,ll>> p(n);
    rep(i,n){
        int a;
        cin >> a;
        p[i] = {a, a};
    }
    
    segtree<pair<ll,ll>, op, e> seg(p);

    ll ans = -INF;
    for(int l = 0; l < n - w + 1; l++){
        ll v = seg.prod(l, l + w).first + k * seg.prod(l, l + w).second;
        ans = max(ans, v);
    }

    cout << ans << endl;

    return 0;
}