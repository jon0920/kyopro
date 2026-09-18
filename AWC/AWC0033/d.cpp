#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){

    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<ll,ll>>> G(n);
    rep(i,m){
        ll u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        G[u].push_back({v,c});
        G[v].push_back({u,c});
    }

    vector<ll> dist(n, INF);
    dist[0] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0, 0});

    while(!pq.empty()){
        auto [c, v] = pq.top(); pq.pop();
        if(c > dist[v]) continue;
        
        for(auto [to, cost] : G[v]){
            if(c + cost < dist[to]){
                dist[to] = c + cost;
                pq.push({dist[to], to});
            }
        }
    }

    if(dist[n - 1] <= k) cout << dist[n - 1] << endl;
    else cout << -1 << endl;

    return 0;
}