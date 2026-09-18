#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<ll,ll>;
const ll INF = 4e18;

P op(P a, P b){ return {max(a.first, b.first), min(a.second, b.second)}; }
P e(){ return {-INF, INF}; }

int main(){

    int n, k, d;
    cin >> n >> k >> d;
    vector<pair<ll,ll>> v(n);
    rep(i,n){
        ll h;
        cin >> h;
        v[i] = {h, h};
    }

    segtree<P, op, e> seg(v);
    int r = 0;
    int ans = 0;
    for(int l = 0; l < n; l++){
        while(r < n){
            P temp = seg.prod(l, r + 1);
            if(temp.first - temp.second <= d) r++;
            else break;
        }
        ans = max(ans, r - l);
        if(r == l) r++;
    }

    if(ans < k) ans = -1;
    cout << ans << endl;

    return 0;
}