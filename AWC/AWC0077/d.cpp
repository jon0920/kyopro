#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using P = pair<ll,ll>;
using TP = tuple<ll,ll,int>;
const ll INF = 1e18;

int main(){
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> f(n);
    rep(i,n) cin >> f[i];
    vector<vector<P>> G(n);
    rep(i,m){
        ll u, v, t;
        cin >> u >> v >> t;
        u--, v--;
        G[u].push_back({v, t});
        G[v].push_back({u, t});
    }

    auto comp = [&](TP a, TP b){
        auto [ax, ay, az] = a;
        auto [bx, by, bz] = b;
        return ax > bx;
    };

    vector<ll> dist(n, INF);
    dist[0] = 0;
    priority_queue<TP, vector<TP>, decltype(comp)> pq(comp);
    pq.push({0, 0, f[0]});

    while(!pq.empty()){
        auto [c, v, fv] = pq.top(); pq.pop();
        if(dist[v] != c) continue;
        for(auto [nv, nc] : G[v]){
            if(dist[nv] > dist[v] + nc * fv){
                dist[nv] = dist[v] + nc * fv;
                pq.push({dist[nv], nv, min(fv, f[nv])});
            }
        }
    }

    if(dist[n - 1] == INF) cout << -1 << endl;
    else cout << dist[n - 1] << endl;
    
    return 0;
}