#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<tuple<int,int,ll>> edges(m);
    rep(i,m){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--, v--;
        edges[i] = {u, v, w};
    }

    vector<int> p(m);
    for(int i = m - (n - 1); i < m; i++){
        p[i] = 1;
    }

    ll ans = 1e18;
    do{
        dsu uf(n);
        ll sum = 0;
        rep(i,m){
            if(p[i] == 1){
                auto [u, v, w] = edges[i];
                uf.merge(u, v);
                sum += w;
                sum %= k;
            }
        }
        bool ok = true;
        int L = uf.leader(0);
        rep(i,n) if(uf.leader(i) != L) ok = false;
        if(ok) ans = min(ans, sum);
    }while(next_permutation(p.begin(), p.end()));

    cout << ans << endl;
    
    return 0;
}