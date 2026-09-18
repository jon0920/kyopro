#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct S{
    ll w; int u; int v;
};

int main(){
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<S> e(m);
    rep(i,m){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--, v--;
        e[i] = {w, u, v};
    }
    
    atcoder::dsu uf(n);
    ll ans = 0;
    bool ok = true;
    rep(i,k){
        int x;
        cin >> x;
        x--;
        if(uf.same(e[x].u, e[x].v)) ok = false;
        uf.merge(e[x].u, e[x].v);
        ans += e[x].w;
    }

    sort(e.begin(), e.end(), [](const auto &x, const auto &y){
        return x.w < y.w;
    });
    rep(i,m){
        if(!uf.same(e[i].u, e[i].v)){
            uf.merge(e[i].u, e[i].v);
            ans += e[i].w;
        }
    }

    int L = uf.leader(0);
    rep(i,n) if(uf.leader(i) != L) ok = false;

    if(ok) cout << ans << endl;
    else cout << -1 << endl;
    
    return 0;
}