#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct S{
    ll val; int size;
};
using F = long long;

S op(S a, S b){
    return{a.val + b.val, a.size + b.size};
}
S e(){ return {0, 0}; }
S mapping(F f, S x){ return {x.val + f * x.size, x.size}; }
F composition(F f, F g){ return f + g; }
F id(){ return 0; }

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<S> v(n, {0, 1});
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);

    rep(qi,q){
        int type;
        cin >> type;
        if(type == 1){
            int l, r;
            cin >> l >> r;
            l--;
            seg.apply(l, r, 1);
        } else if(type == 2){
            int p;
            cin >> p;
            p--;
            seg.set(p, {0, 1});
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            cout << seg.prod(l, r).val << endl;
        }
    }

    return 0;
}