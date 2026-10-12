#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using mint = modint998244353;

struct S{
    mint RGB, RG, GB, R, G, B;
};

S op(S x, S y){
    S res;
    res.RGB = x.RGB + (x.RG * y.B) + (x.R * y.GB) + y.RGB;
    res.RG = x.RG + (x.R * y.G) + y.RG;
    res.GB = x.GB + (x.G * y.B) + y.GB;
    res.R = x.R + y.R;
    res.G = x.G + y.G;
    res.B = x.B + y.B;
    return res;
}

S e(){ return {0, 0, 0, 0, 0, 0}; }

S update(char c, ll x){
    S res = {0, 0, 0, 0, 0, 0};

    if(c == 'R') res.R = x;
    if(c == 'G') res.G = x;
    if(c == 'B') res.B = x;

    return res;
}

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    string s;
    cin >> s;
    
    vector<S> init(n);
    rep(i,n){
        init[i] = update(s[i], a[i]);
    }
    segtree<S, op, e> seg(init);

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            ll i, x;
            cin >> i >> x;
            i--;
            a[i] = x;
            seg.set(i, update(s[i], a[i]));
        } else {
            ll l, r;
            cin >> l >> r;
            l--;
            cout << seg.prod(l, r).RGB.val() << endl;
        }
    }
    
    return 0;
}