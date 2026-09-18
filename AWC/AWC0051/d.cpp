#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using P = pair<ll,ll>;
const ll INF = 4e18;

int main(){

    ll n, m, k, t;
    cin >> n >> m >> k >> t;
    vector<vector<P>> G(n);
    rep(i,m){
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    vector<bool> flood(n);
    rep(i,k){
        int g;
        cin >> g;
        g--;
        flood[g] = true;
    }

    vector<ll> dist(n, INF);
    if(flood[0]) dist[0] = t;
    else dist[0] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({dist[0], 0});
    
    while(!pq.empty()){
        auto [d, v] = pq.top(); pq.pop();
        if(dist[v] < d) continue;

        for(auto [nv, nd] : G[v]){
            if(dist[nv] <= d + nd + (flood[nv] ? t : 0)) continue;

            dist[nv] = d + nd + (flood[nv] ? t : 0);
            pq.push({dist[nv], nv});
        }
    }

    cout << dist[n - 1] << endl;

    return 0;
}