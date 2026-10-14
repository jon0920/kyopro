#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

struct S{
    ll u_min, u_max, v_min, v_max;
};

S op(S a, S b){
    S res;
    res.u_min = min(a.u_min, b.u_min);
    res.u_max = max(a.u_max, b.u_max);
    res.v_min = min(a.v_min, b.v_min);
    res.v_max = max(a.v_max, b.v_max);
    return res;
};
S e(){ return {INF, -INF, INF, -INF}; }

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<S> node(n);
    rep(i,n){
        ll x, y;
        cin >> x >> y;
        node[i] = {x + y, x + y, x - y, x - y};
    }
    
    segtree<S, op, e> seg(node);

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            ll i, x, y;
            cin >> i >> x >> y;
            i--;
            seg.set(i, {x + y, x + y, x - y, x - y});
        } else {
            ll l, r, x, y;
            cin >> l >> r >> x >> y;
            l--;
            ll u = x + y, v = x - y;
            S res = seg.prod(l, r);
            cout << max({abs(res.u_min - u), abs(res.u_max - u), abs(res.v_min - v), abs(res.v_max - v)}) << endl;
        }
    }
    
    return 0;
}