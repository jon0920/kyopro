#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using P = pair<ll,ll>;

int main(){
    
    int n;
    cin >> n;
    vector<tuple<ll,ll,ll>> edges(n - 1);
    rep(i,n - 1){
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges[i] = {u, v, w};
    }
    
    vector<vector<P>> G(n);
    for(auto [u, v, w] : edges){
        G[v].push_back({u, w});
        G[u].push_back({v, w});
    }

    vector<int> tin(n), tout(n);
    vector<int> depth(n);
    const int LOG = 19;
    vector<vector<int>> doubling(n, vector<int>(LOG, -1));
    int time = 0;
    auto dfs = [&](auto dfs, int v, int pre) -> void {
        tin[v] = time;
        time++;

        doubling[v][0] = pre;
        for(int k = 1; k < LOG; k++){
            int mid = doubling[v][k - 1];
            doubling[v][k] = (mid == -1 ? -1 : doubling[mid][k - 1]);
        }

        for(auto [nv, w] : G[v]){
            if(nv != pre){
                depth[nv] = depth[v] + 1;
                dfs(dfs, nv, v);
            }
        }
        tout[v] = time - 1;
    };

    dfs(dfs, 0, -1);

    fenwick_tree<ll> fw(n + 1);
    for(auto [u, v, w] : edges){
        int c = (depth[u] > depth[v] ? u : v);
        fw.add(tin[c], w);
        fw.add(tout[c] + 1, -w);
    }

    auto LCA = [&](int a, int b){
        if(depth[a] < depth[b]) swap(a, b);
        int diff = depth[a] - depth[b];
        rep(k, LOG) if((diff >> k) & 1) a = doubling[a][k];
        if(a == b) return a;
        for(int k = LOG - 1; k >= 0; k--){
            if(doubling[a][k] != doubling[b][k]){
                a = doubling[a][k];
                b = doubling[b][k];
            }
        }
        return doubling[a][0];
    };

    auto calc = [&](int v){
        return fw.sum(0, tin[v] + 1);
    };
    
    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int i; ll w;
            cin >> i >> w;
            i--;
            auto [u, v, old_w] = edges[i];
            int c = (depth[u] > depth[v] ? u : v);
            ll d = w - old_w;
            fw.add(tin[c], d);
            fw.add(tout[c] + 1, -d);
            edges[i] = {u, v, w};
        } else {
            int u, v;
            cin >> u >> v;
            u--, v--;
            int r = LCA(u, v);
            cout << calc(u) + calc(v) - 2 * calc(r) << endl;
        }
    }
    
    return 0;
}