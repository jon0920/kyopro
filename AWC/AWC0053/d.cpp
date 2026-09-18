#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using S = long long;
using F = long long;

const S INF = 4e18;
const F ID = 4e18;

S op(S a, S b){ return max(a, b); }
S e(){ return -INF; }
S mapping(F f, S x){ return (f == ID ? x : f); }
F composition(F f, F g){ return (f == ID ? g : f); }
F id(){ return ID; }

int main(){

    int n, m;
    cin >> n >> m;
    vector<ll> v(n, 0);
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
    rep(i,m){
        ll l, r, c;
        cin >> l >> r >> c;
        l--;
        seg.apply(l, r, c);
    }

    rep(i,n){
        cout << seg.get(i) << " ";
    }
    cout << endl;
    
    return 0;
}