#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<ll,ll>;
const ll INF = 1e18;

int main(){
    
    int n, m, s, g, t;
    cin >> n >> m >> s >> g >> t;
    s--, g--, t--;
    vector<vector<P>> G(n);
    rep(i,m){
        ll u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        G[u].push_back({v, c});
        G[v].push_back({u, c});
    }
    
    auto dijkstra = [&](int x, int y){
        vector<ll> dist(n, INF);
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, x});
        dist[x] = 0;
        while(!pq.empty()){
            auto [cost, v] = pq.top(); pq.pop();
            if(dist[v] != cost) continue;
            for(auto [nv, nc] : G[v]){
                if(dist[nv] > dist[v] + nc){
                    dist[nv] = dist[v] + nc;
                    pq.push({dist[nv], nv});
                }
            }
        }
        return dist[y];
    };

    ll d1 = dijkstra(s,g);
    ll d2 = dijkstra(g,t);

    if(d1 == INF || d2 == INF) cout << -1 << endl;
    else cout << d1 + d2 << endl;
    
    return 0;
}