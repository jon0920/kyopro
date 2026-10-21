#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using mint = modint998244353;

struct S{
    mint val;
    int size;
};
struct F{
    bool assign;
    mint val;
};

S op(S a, S b){ return {a.val + b.val, a.size + b.size}; }
S e(){ return {0, 0}; }
S mapping(F f, S x){
    if(f.assign) x.val = f.val * x.size;
    return x;
}
F composition(F f, F g){ return (f.assign ? f : g); }
F id(){ return {false, 0}; }

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    vector<S> init(n);
    rep(i,n) init[i] = {a[i], 1};
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(init);

    rep(i,m){
        int l, r;
        cin >> l >> r;
        l--;
        mint sum = seg.prod(l, r).val;
        mint inv_len = mint(r - l).inv();
        mint res = sum * inv_len;

        seg.apply(l, r, {true, res});
    }

    rep(i,n) cout << seg.get(i).val.val() << " ";
    cout << endl; 
    
    return 0;
}