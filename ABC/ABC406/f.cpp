#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<pair<int,int>> edges(n -1);
    rep(i,n - 1){
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[i] = {u, v};
    }
    vector<vector<int>> G(n);
    for(auto [u, v] : edges){
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> in(n), out(n);
    int cur = 0;
    auto dfs = [&](auto dfs, int v, int pre) -> void {
        in[v] = cur;
        cur++;
        for(int nv : G[v]){
            if(nv != pre){
                dfs(dfs, nv, v);
            }
        }
        out[v] = cur;
    };

    dfs(dfs, 0, -1);

    fenwick_tree<ll> fw(n);
    rep(i,n) fw.add(i, 1);

    ll tot = n;
    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            ll x, w;
            cin >> x >> w;
            x--;
            fw.add(in[x], w);
            tot += w;
        } else {
            int y;
            cin >> y;
            auto [u, v] = edges[y - 1];
            if(in[u] > in[v]) swap(u, v);
            ll sum = fw.sum(in[v], out[v]);
            cout << abs(sum * 2 - tot) << endl;
        }
    }

    return 0;
}