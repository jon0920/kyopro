#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 4e18;

ll op(ll a, ll b){ return min(a, b); }
ll e() { return INF; }

int main(){

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    segtree<ll,op,e> seg(n);
    seg.set(0, a[0]);

    for(ll i = 1; i < n; i++){
        seg.set(i, seg.prod(max(0LL, i - k), i) + a[i]);
    }
    cout << seg.get(n - 1) << endl;

    return 0;
}