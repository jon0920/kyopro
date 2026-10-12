#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct S{
    array<ll,3> cnt{};
    ll inv = 0;
};

S op(S a, S b){
    S res;

    for(int x = 0; x < 3; x++){
        res.cnt[x] = a.cnt[x] + b.cnt[x];
    }
    res.inv = a.inv + b.inv + (a.cnt[1] * b.cnt[0]) + (a.cnt[2] * (b.cnt[1] + b.cnt[0]));

    return res;
}

S e(){ return S{}; }

S pre(int x){
    S res;
    res.cnt[x] = 1;
    return res;
}

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<S> init(n);
    rep(i,n){
        int x;
        cin >> x;
        init[i] = pre(x);
    }

    segtree<S, op, e> seg(init);

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int i, x;
            cin >> i >> x;
            i--;
            seg.set(i, pre(x));
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            cout << seg.prod(l, r).inv << endl;
        }
    }
    
    return 0;
}