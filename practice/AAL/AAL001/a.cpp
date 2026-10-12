#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

ll op(ll a, ll b){ return min(a, b); }
ll e(){ return 1e9; }

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    segtree<ll, op, e> seg(a);

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int i, x;
            cin >> i >> x;
            i--;
            seg.set(i, x);
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            cout << seg.prod(l, r) << endl;
        }
    }
    
    return 0;
}