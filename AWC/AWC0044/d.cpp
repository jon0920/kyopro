#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using P = pair<ll,ll>;
const ll INF = 4e18;

int main(){

    int n, m, k;
    cin >> n >> m >> k;
    vector<tuple<int,int,ll>> uvw(m);
    rep(i,m){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--, v--;
        uvw[i] = {u, v, w};
    }
    rep(i,k){
        int c;
        cin >> c;
        c--;
        auto &[u, v, w] = uvw[c];
        w *= 2;
    }

    vector<vector<P>> G(n);
    for(auto [u, v, w] : uvw){
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    vector<ll> dist(n, INF);
    dist[0] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0,0});
    
    while(!pq.empty()){
        auto [c, v] = pq.top(); pq.pop();
        if(dist[v] < c) continue;

        for(auto [nv, nc] : G[v]){
            if(dist[nv] <= dist[v] + nc) continue;
            dist[nv] = dist[v] + nc;
            pq.push({dist[nv], nv});
        }
    }

    if(dist[n - 1] != INF) cout << dist[n - 1] << endl;
    else cout << -1 << endl;

    return 0;
}