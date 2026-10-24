#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using P = pair<int,int>;
const int INF = 1e9;

int main(){
    
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--, t--;
    vector<vector<P>> G(n);
    vector<int> mn(n, INF);
    vector<P> edges(m);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[i] = {u, v};
        mn[u] = min(mn[u], v);
    }

    for(auto [u, v] : edges){
        if(mn[u] == v){
            G[u].push_back({v, 0});
        } else {
            G[u].push_back({v, 1});
        }
    }

    priority_queue<P, vector<P>, greater<P>> pq;
    vector<int> dist(n, INF);
    pq.push({0, s});
    dist[s] = 0; 

    while(!pq.empty()){
        auto [c, v] = pq.top(); pq.pop();
        if(dist[v] != c) continue;
        for(auto [nv, nc] : G[v]){
            if(dist[nv] <= dist[v] + nc) continue;
            dist[nv] = dist[v] + nc;
            pq.push({dist[nv], nv});
        }
    }

    if(dist[t] == INF) cout << -1 << endl;
    else cout << dist[t] << endl;
    
    return 0;
}