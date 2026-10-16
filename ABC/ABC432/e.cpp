#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

ll MAX = 500100;
struct S{
    ll cnt;
    ll sum;
};
S op(S a, S b){
    return {a.cnt + b.cnt, a.sum + b.sum};
}
S e(){ return {0, 0}; }

int main(){
    
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    segtree<S, op, e> seg(MAX);
    rep(i,n){
        S p = seg.get(a[i]);
        seg.set(a[i], {p.cnt + 1, p.sum + a[i]});
    }

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            ll x, y;
            cin >> x >> y;
            x--;
            S xx = seg.get(a[x]);
            seg.set(a[x], {xx.cnt - 1, xx.sum - a[x]});
            
            S yy = seg.get(y);
            seg.set(y, {yy.cnt + 1, yy.sum + y});
            a[x] = y;
        } else {
            ll l, r;
            cin >> l >> r;
            if(l >= r){
                cout << l * n << endl;
            } else {
                ll ans = 0;
                ans += seg.prod(0, l + 1).cnt * l;
                ans += seg.prod(l + 1, r).sum;
                ans += seg.prod(r, MAX).cnt * r;
                cout << ans << endl;
            }
        }
    }
    
    return 0;
}