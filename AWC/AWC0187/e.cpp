#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct S{
    ll val; int size;
};
using F = long long;

S op(S a, S b){ return {a.val + b.val, a.size + b.size}; }
S e(){ return {0, 0}; }
S mapping(F f, S x){
    return {x.val + f * x.size, x.size};
}
F composition(F f, F g){
    return f + g;
}
F id(){ return 0; }

int seg_op(int a, int b){ return a + b; }
int seg_e(){ return 0; }

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<S> v(n);
    rep(i,n){
        ll x;
        cin >> x;
        v[i] = {x, 1};
    }

    lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
    segtree<int, seg_op, seg_e> cnt_seg(n);
    rep(i,n) cnt_seg.set(i, 1);
    fenwick_tree<ll> sum_fw(n);
    
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int l, r; ll x;
            cin >> l >> r >> x;
            l--;
            seg.apply(l, r, x);
        } else if(type == 2){
            int p;
            cin >> p;
            p--;
            sum_fw.add(p, seg.get(p).val);
            cnt_seg.set(p, 0);
        } else {
            int k;
            cin >> k;
            int j = cnt_seg.max_right(0, [k](int r){return r < k;});
            cout << sum_fw.sum(0, j) << endl;
        }
    }

    return 0;
}