#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using S = long long;
using F = long long;

const S INF = 4e18;

S op(S u, S v) { return max(u, v); }
S e() { return -INF; }
S mapping(F f, S x) { return f + x; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];

    vector<ll> v(n);
    ll sum = 0;
    rep(i,n){
        v[i] = a[i] - sum;
        sum += b[i];
    }

    lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int i;
            ll x, y;
            cin >> i >> x >> y;
            i--;
            ll da = x - a[i];
            ll crr = seg.get(i);
            seg.set(i, crr + da);
            a[i] = x;

            ll db = y - b[i];
            if(i + 1 < n) seg.apply(i + 1, n, -db);
            b[i] = y;
        } else {
            ll s;
            cin >> s;
            cout << seg.max_right(0, [&](S x){return x <= s;}) << endl;
        }
    }
    
    return 0;
}