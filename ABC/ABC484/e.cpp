#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

ll op(ll a, ll b){ return a + b; }
ll e(){ return 0; }

int main(){
    
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> sum(n + 1);
    rep(i,n) sum[i + 1] = sum[i] + a[i];

    vector<ll> v = sum;
    v.push_back(-4e18);
    v.push_back(4e18);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int num = 0;
    map<ll,ll> mp;
    for(ll x : v){
        mp[x] = num;
        num++;
    }

    segtree<ll, op, e> seg(num);
    for(ll x : sum){
        ll cnt = seg.get(mp[x]);
        seg.set(mp[x], cnt + 1);
    }
    ll ans = 0;
    for(ll x : sum){
        auto L = mp.lower_bound(l + x);
        auto R = mp.upper_bound(r + x);

        ll cur = seg.get(mp[x]);
        seg.set(mp[x], cur - 1);
        ans += seg.prod(L->second, R->second);
    }

    cout << ans << endl;
    
    return 0;
}