#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

ll op(ll a, ll b){ return max(a, b); }
ll e(){ return -INF; }

int main(){
    
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> sum(n + 1);
    rep(i,n) sum[i + 1] = sum[i] + a[i];

    segtree<ll, op, e> seg(sum);

    ll cur = 0;
    ll ans = 0;
    rep(i,n){
        ans = max(ans, cur + seg.prod(0, i + 2));
        cur += sum[i + 1];
    }

    cout << ans << endl;
    
    return 0;
}