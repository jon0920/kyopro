#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using P = pair<ll,ll>;
const ll INF = 1e18;

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<tuple<ll,ll,ll>> edges(m);
    rep(i,m){
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges[i] = {u, v, w};
    }
    int k;
    cin >> k;
    vector<bool> e(m, true);
    rep(i,k){
        int x;
        cin >> x;
        x--;
        e[x] = false;
    }

    vector<vector<P>> G(n);
    rep(i,m){
        auto [u, v, w] = edges[i];
        if(e[i]){
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
    }

    auto bfs = [&](vector<vector<P>> &G){
        vector<ll> dist(n, INF);
        dist[0] = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});

        while(!pq.empty()){
            auto [c, v] = pq.top(); pq.pop();
            if(dist[v] != c) continue;
            for(auto [nv, nc] : G[v]){
                if(dist[nv] <= dist[v] + nc) continue;
                dist[nv] = dist[v] + nc;
                pq.push({dist[nv], nv});
            }
        }

        return (dist[n - 1] == INF ? -1 : dist[n - 1]);
    };

    ll ans2 = bfs(G);
    rep(i,m){
        auto [u, v, w] = edges[i];
        if(!e[i]){
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
    }
    ll ans1 = bfs(G);

    cout << ans1 << endl << ans2 << endl;
    
    return 0;
}