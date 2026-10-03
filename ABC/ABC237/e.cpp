#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using P = pair<ll,ll>;
const ll INF = 1e18;

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];

    vector<vector<P>> G(n);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        ll d_uv = (h[u] < h[v] ? h[v] - h[u] : 0);
        ll d_vu = (h[v] < h[u] ? h[u] - h[v] : 0);

        G[u].push_back({v, d_uv});
        G[v].push_back({u, d_vu});
    }

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

    ll ans = -INF;
    rep(i,n){
        ans = max(ans, (h[0] - h[i]) - dist[i]);
    }
    cout << ans << endl;
    
    return 0;
}