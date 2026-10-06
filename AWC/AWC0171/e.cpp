#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<ll,ll>;

P op(P a, P b){
    vector<ll> v = {a.first, a.second, b.first, b.second};
    sort(v.rbegin(), v.rend());
    return {v[0], v[1]};
}

P e(){ return {0, 0}; }

int main(){
    
    ll n, q, k;
    cin >> n >> q >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<P> d(n - 1);
    rep(i,n - 1){
        ll diff = abs(a[i + 1] - a[i]);
        d[i] = {diff, 0};
    }

    segtree<P, op, e> seg(d);

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            ll p, v;
            cin >> p >> v;
            p--;
            a[p] = v;
            if(p - 1 >= 0){
                ll diff = abs(a[p] - a[p - 1]);
                seg.set(p - 1, {diff, 0});
            } 
            if(p + 1 < n){
                ll diff = abs(a[p] - a[p + 1]);
                seg.set(p, {diff, 0});
            }
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            P ans = seg.prod(l, r);
            if(ans.first <= k) cout << ans.first << endl;
            else cout << ans.second << endl;
        }
    }
    
    return 0;
}