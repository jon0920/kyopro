#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

ll op(ll a, ll b){ return a + b; }
ll e(){ return 0; }
ll target;
bool f(ll v){ return v < target; }

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
            ll i, x;
            cin >> i >> x;
            i--;
            seg.set(i, x);
        } else if(type == 2){
            ll l, t;
            cin >> l >> t;
            l--;
            target = t;
            int ans = seg.max_right<f>(l) + 1;
            cout << ans << endl;
        } else {
            ll r, t;
            cin >> r >> t;
            target = t;
            int ans = seg.min_left<f>(r);
            cout << ans << endl;
        }
    }
    
    return 0;
}