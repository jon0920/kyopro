#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

ll op(ll a, ll b){ return a + b; }
ll e() { return 0; }

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> b(n);
    ll sum = 0;
    rep(i,n){
        cin >> a[i];
        if(a[i] > 0) sum += a[i];
        b[i] = min(0LL, a[i]);
    }

    segtree<ll, op, e> seg(b);
    ll loss = -1e18; int id;
    rep(i,n - k + 1){
        ll d = seg.prod(i, i + k);
        if(loss < d){
            id = i;
            loss = d;
        }
    }

    vector<bool> use(n);
    ll ans = 0;
    for(int i = id; i < id + k; i++){
        ans += a[i];
        use[i] = true;
    }

    rep(i,n){
        if(!use[i] && a[i] > 0) ans += a[i];
    }

    cout << ans << endl;
    
    return 0;
}