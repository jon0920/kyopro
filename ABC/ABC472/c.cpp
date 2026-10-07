#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

ll op(ll a, ll b){
    return a + b;
}
ll e(){ return 0; }

int main(){
    
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    segtree<ll, op, e> seg(a);

    rep(i,n){
        ll sum = seg.prod(max(0LL, i - m + 1), i + 1);
        if(sum <= k){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
            seg.set(i, 0);
        }
    }
    
    return 0;
}