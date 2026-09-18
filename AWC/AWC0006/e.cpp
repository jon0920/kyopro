#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

ll op(ll a, ll b){
    return a + b;
}
ll e(){
    return 0;
}

int main(){

    int n, q;
    cin >> n >> q;
    vector<ll> s(n);
    rep(i,n) cin >> s[i];
    
    segtree<ll, op, e> seg(s);

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int l, r;
            cin >> l >> r;
            l--;
            cout << seg.prod(l, r) << endl;
        }
        else{
            ll x, v;
            cin >> x >> v;
            x--;
            seg.set(x, v);
        }
    }

    return 0;
}