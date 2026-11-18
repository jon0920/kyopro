#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<tuple<ll,int,int>> edges(m);
    rep(i,m){
        int u, v; ll w;
        cin >> u >> v >> w;
        u--, v--;
        edges[i] = {w, u, v};
    }
    sort(edges.begin(), edges.end());

    vector<int> cnt_a(n), cnt_b(n);
    rep(i,k){
        int a;
        cin >> a;
        cnt_a[a - 1]++;
    }
    rep(i,k){
        int b;
        cin >> b;
        cnt_b[b - 1]++;
    }

    dsu uf(n);
    ll ans = 0;
    for(auto [w, u, v] : edges){
        if(!uf.same(u, v)){
            int ru = uf.leader(u), rv = uf.leader(v);
            ll cnt_a_u = cnt_a[ru], cnt_a_v = cnt_a[rv];
            ll cnt_b_u = cnt_b[ru], cnt_b_v = cnt_b[rv]; 
            uf.merge(u, v);

            int nr = uf.leader(v);
            cnt_a[nr] = cnt_a_u + cnt_a_v;
            cnt_b[nr] = cnt_b_u + cnt_b_v;

            ll num = min(cnt_a[nr], cnt_b[nr]);
            ans += num * w;
            cnt_a[nr] -= num;
            cnt_b[nr] -= num;
        }
    }

    cout << ans << endl;
    
    return 0;
}