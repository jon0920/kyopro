#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using S = long long;
using F = long long;

const S INF = 4e18;

S op(S a, S b){ return a + b; }
S e(){ return INF; }
S mapping(F f, S x){ return f + x; }
F composition(F f, F g){return f + g; }
F id(){ return 0; }

int main(){

    ll n, k, t, c;
    cin >> n >> k >> t >> c;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);

    ll ans = 0;
    rep(i,n){
        ll d = seg.get(i);
        if(d < t){
            seg.apply(i, min(i + k, n), t - d);
            ans += (t - d) * c;
        }
    }

    cout << ans << endl;

    return 0;
}