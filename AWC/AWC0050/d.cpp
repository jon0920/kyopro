#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using P = pair<ll,ll>;
const ll INF = 4e18;

int main(){

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<P>> G(n);
    rep(i,m){
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    
    vector<ll> cost(n);
    rep(i,k){
        ll l, c;
        cin >> l >> c;
        l--;
        cost[l] = c;
    }

    vector<ll> dist(n, INF);
    dist[0] = cost[0];
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({dist[0], 0});

    while(!pq.empty()){
        auto [d, v] = pq.top(); pq.pop();
        if(dist[v] < d) continue;

        for(auto [nv, w] : G[v]){
            if(dist[nv] <= d + w + cost[nv]) continue;
            dist[nv] = d + w + cost[nv];
            pq.push({dist[nv], nv});
        }   
    }

    cout << dist[n - 1] << endl;

    return 0;
}