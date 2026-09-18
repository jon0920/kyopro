#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using mint = modint998244353;

struct S{
    mint sum;
    mint sum_sq;
    int size;
};

using F = mint;
S op(S a, S b){
    return {a.sum + b.sum, a.sum_sq + b.sum_sq, a.size + b.size};
}
S e(){ return {0, 0, 0}; }
S mapping(F f, S x){
    if(f == 0) return x;
    S res = x;
    res.sum_sq = x.sum_sq + (f * 2 * x.sum) + (f * f * x.size);
    res.sum = x.sum + (f * x.size);
    return res;
}
F composition(F f, F g){ return f + g; }
F id(){ return 0; }

int main(){

    int n, q;
    cin >> n >> q;

    vector<S> v(n, {0, 0, 1});
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);

    while(q--){
        int l, r;
        ll a;
        cin >> l >> r >> a;
        l--;
        seg.apply(l, r, (mint)a);

        S res = seg.prod(l, r);
        mint ans = (res.sum * res.sum - res.sum_sq) / 2;

        cout << ans.val() << endl;
    }

    return 0;
}