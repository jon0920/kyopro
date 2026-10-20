#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

using P = pair<ll,ll>;
P op(P a, P b){ return min(a, b); }
P e(){ return {INF, INF}; }

int main(){
    
    ll n, m, t;
    cin >> n >> m >> t;
    vector<P> init(n);
    rep(i,n) init[i].second = i;

    vector<ll> ans(n);
    segtree<P, op, e> seg(init);
    rep(i,m){
        ll s, l, r;
        cin >> s >> l >> r;
        l--;
        auto [cnt, id] = seg.prod(l, r);
        seg.set(id, {cnt + 1, id});
        ans[id] += max(100 - (t - s), 0LL);
    }

    for(ll x : ans) cout << x << " ";
    cout << endl;
    
    return 0;
}