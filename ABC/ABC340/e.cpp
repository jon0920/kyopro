#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using S = long long;
using F = long long;

S op(S a, S b){ return a + b; }
S e(){ return 0; }
S mapping(F f, S x){ return f + x; }
F composition(F f, F g){ return f + g; }
F id(){ return 0; }

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);

    rep(i,m){
        int b;
        cin >> b;
        ll cnt = seg.get(b);
        seg.set(b, 0);
        ll x = cnt / n;
        seg.apply(0, n, x);
        ll y = cnt % n;
        if(n - 1 - b < y){
            ll rem = y - (n - (b + 1));
            seg.apply(b + 1, n, 1);
            seg.apply(0, rem, 1);
        } else {
            seg.apply(b + 1, b + 1 + y, 1);
        }
    }

    rep(i,n) cout << seg.get(i) << " ";
    cout << endl;
    
    return 0;
}