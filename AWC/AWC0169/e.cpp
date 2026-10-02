#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using P = pair<ll,ll>;
const ll INF = 1e18;

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<ll> p(n);
    rep(i,n) cin >> p[i];
    vector<vector<P>> G(n);
    rep(i,m){
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        G[u].push_back({v, w - p[v]});
        G[v].push_back({u, w - p[u]});
    }

    vector<bool> seen(n);
    seen[0] = true;
    vector<ll> dist(n, INF);
    dist[0] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 0});
    while(!pq.empty()){
        auto [c, v] = pq.top(); pq.pop();
        if(dist[v] != c) continue;
        for(auto [nv, nc] : G[v]){
            if(dist[nv] <= dist[v] + nc) continue;

            if(seen[nv]){
                cout << "-inf" << endl;
                return 0;
            }

            dist[nv] = dist[v] + nc;
            seen[nv] = true;
            pq.push({dist[nv], nv});
        }
    }

    cout << dist[n - 1] << endl;
    
    return 0;
}