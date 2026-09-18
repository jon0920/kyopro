#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using S = long long;
using F = long long;
const S INF = 4e18;

S op(S a, S b){ return max(a, b); }
S e(){ return -INF; }
S mapping(F f, S x){ return f + x; }
S composition(F f, F g){ return f + g; }
F id(){ return 0; }

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
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            seg.apply(l, r, x);
        } else {
            int p;
            cin >> p;
            p--;
            cout << seg.get(p) << endl;
        }
    }

    return 0;
}