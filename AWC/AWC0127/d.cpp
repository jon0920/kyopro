#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, m, k;
    cin >> n >> m >> k;
    vector<tuple<int,int,ll>> e(m);
    rep(i,m){
        int u, v; ll c;
        cin >> u >> v >> c;
        u--, v--;
        e[i] = {u, v, c};
    }
    sort(e.begin(), e.end(), [](const auto &x, const auto &y){
        auto [ux, vx, cx] = x;
        auto [uy, vy, cy] = y;
        return cx < cy;
    });

    dsu uf(n);
    ll mx = 0;
    ll ans = 0;
    for(auto [u, v, c] : e){
        if(!uf.same(u, v)){
            uf.merge(u, v);
            mx = max(mx, c);
            ans += c;
        }
    }

    cout << ans + mx * k << endl;
    
    return 0;
}