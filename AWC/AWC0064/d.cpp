#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct S{
    int u; int v; ll c;
};

int main(){

    int n, m;
    cin >> n >> m;
    dsu uf(n);
    vector<S> b(m);
    rep(i,m){
        int u, v;
        ll c;
        cin >> u >> v >> c;
        u--, v--;
        b[i] = {u, v, c};
    }
    sort(b.begin(), b.end(), [](const auto &x, const auto &y){
        return x.c < y.c;
    });

    ll ans = 0;
    rep(i,m){
        if(!uf.same(b[i].u, b[i].v)){
            uf.merge(b[i].u, b[i].v);
            ans += b[i].c;
        }
    }

    if(uf.size(0) == n) cout << ans << endl;
    else cout << -1 << endl;

    return 0;
}