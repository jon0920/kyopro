#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using P = pair<ll,ll>;
const ll INF = 1e18;

int main(){
    
    int n, m, s;
    cin >> n >> m >> s;
    s--;
    vector<vector<P>> G(n);
    rep(i,m){
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    vector<ll> dist(n, INF);
    dist[s] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, s});

    while(!pq.empty()){
        auto [c, v] = pq.top(); pq.pop();
        if(dist[v] != c) continue;
        for(auto [nv, nc] : G[v]){
            if(dist[nv] <= dist[v] + nc) continue;
            dist[nv] = dist[v] + nc;
            pq.push({dist[nv], nv});
        }
    }

    ll ans = 0;
    rep(i,n){
        if(dist[i] != INF) ans += dist[i];
    }

    cout << ans << endl;

    return 0;
}