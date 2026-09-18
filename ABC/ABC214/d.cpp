#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<tuple<ll,ll,ll>> e(n - 1);
    rep(i,n - 1){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        e[i] = {u, v, w};
    }

    sort(e.begin(), e.end(),[](const auto &a, const auto &b){
        auto &[au, av, aw] = a;
        auto &[bu, bv, bw] = b;
        return aw < bw;
    });

    ll ans = 0;
    dsu uf(n);
    for(auto v : e){
        auto [a, b, w] = v;
        ans += w * uf.size(a) * uf.size(b);
        uf.merge(a,b);
    }
    cout << ans << endl;

    return 0;
}