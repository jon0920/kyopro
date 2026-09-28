#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

ll op(ll a, ll b){
    return max(a, b);
}

ll e(){ return 0; }

int main(){
    
    ll n, l, r;
    cin >> n >> l >> r;
    ll tot = 0;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
        tot += a[i];
    }
    
    vector<ll> d_l(n), d_r(n);
    rep(i,n) d_l[i] = a[i] - l;
    rep(i,n) d_r[i] = a[i] - r;

    vector<ll> sum_d_l(n + 1), sum_d_r(n + 1);
    rep(i,n) sum_d_l[i + 1] = sum_d_l[i] + d_l[i];
    for(int i = n; i >= 1; i--) sum_d_r[i - 1] = sum_d_r[i] + d_r[i - 1];

    segtree<ll, op, e> seg_l(sum_d_l);
    segtree<ll, op, e> seg_r(sum_d_r);

    ll ans = tot;
    rep(i,n + 2){
        ll L = seg_l.prod(0, i);
        ll R = seg_r.prod(i, n + 1);
        ans = min(ans, tot - (L + R));
    }

    cout << ans << endl;
    
    return 0;
}