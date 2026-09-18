#include <bits/stdc++.h>
#include <atcoder/maxflow>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, k, m;
    cin >> n >> k >> m;
    vector<int> b(n), w(k);
    ll sum = 0;
    rep(i,n){
        cin >> b[i];
        sum += b[i];
    }
    rep(i,k) cin >> w[i];

    vector<tuple<int,int,int>> e(m);
    rep(i,m){
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        e[i] = {u, v, c};
    }

    int q;
    cin >> q;
    vector<bool> ok(k, true);
    while(q--){
        int s;
        cin >> s;
        s--;
        ok[s] = false;

        mf_graph<ll> g(n + k + 2);
        for(auto [u, v, c] : e){
            g.add_edge(u, v, c);
            g.add_edge(v, u, c);
        }

        rep(i,n) g.add_edge(n + k, i, b[i]);
        rep(i,k) if(ok[i]) g.add_edge(n + i, n + k + 1, w[i]);

        ll flow = g.flow(n + k, n + k + 1);
        if(flow == sum) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}