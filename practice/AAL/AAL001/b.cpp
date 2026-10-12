#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using S = long long;
using F = long long;

S op(S a, S b){ return min(a, b); }
S e(){ return 4e18; }
F mapping(F f, S x){ return f + x; }
F composition(F f, F g){ return f + g; }
F id() { return 0; }

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            ll l, r, x;
            cin >> l >> r >> x;
            l--;
            seg.apply(l, r, x);
        } else {
            ll l, r;
            cin >> l >> r;
            l--;
            cout << seg.prod(l, r) << endl;
        }
    }
    
    return 0;
}