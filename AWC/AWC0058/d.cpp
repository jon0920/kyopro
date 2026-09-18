#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;
using P = pair<ll,ll>;

int main(){

    int n, m, k;
    cin >> n >> m >> k;
    k--;
    vector<vector<P>> G(n);
    rep(i,m){
        ll u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        G[u].push_back({v, c});
        G[v].push_back({u, c});
    }

    vector<ll> dist(n, INF);
    dist[k] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, k});

    while(!pq.empty()){
        auto [c, v] = pq.top(); pq.pop();
        if(dist[v] != c) continue;

        for(auto [nv, nc] : G[v]){
            if(dist[nv] <= dist[v] + nc) continue;
            dist[nv] = dist[v] + nc;
            pq.push({dist[nv], nv});
        }
    }

    if(dist[0] == INF || dist[n - 1] == INF) cout << -1 << endl;
    else cout << dist[0] + dist[n - 1] << endl;

    return 0;
}