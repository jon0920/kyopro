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

    int n, k, m;
    cin >> n >> k >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    
    vector<ll> sum(n + 1);
    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i - 1];
    
    segtree<ll, op, e> seg0(n + 1), seg1(n + 1);
    seg0.set(0,0);
    seg1.set(0,0);

    for(int i = 1; i <= n; i++){
        seg0.set(i, seg1.prod(max(0, i - m + 1), i) - sum[i]);
        seg1.set(i, seg0.prod(max(0, i - k + 1), i) + sum[i]);
    }
    cout << max(seg0.get(n) + sum[n], seg1.get(n)) << endl;

    return 0;
}