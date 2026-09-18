#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

ll op(ll a, ll b){ return max(a, b); }
ll e(){ return 0; }

int main(){

    int n, k;
    cin >> n >> k;
    vector<ll> a(n + k + 1);
    for(int i = k + 1; i < n + k + 1; i++) cin >> a[i];

    atcoder::segtree<ll, op, e> seg(a);
    for(int i = k + 1; i < n + k + 1; i++){
        ll mx = seg.prod(0, i - k);
        seg.set(i, mx + a[i]);
    }

    cout << seg.all_prod() << endl;

    return 0;
}