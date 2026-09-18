#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using P = pair<ll,ll>;

int main(){
    
    ll n, m, y;
    cin >> n >> m >> y;
    vector<vector<P>> G(n + 1);
    rep(i,m){
        ll u, v, t;
        cin >> u >> v >> t;
        u--, v--;
        G[u].push_back({v, t});
        G[v].push_back({u, t});
    }
    rep(i,n){
        ll x;
        cin >> x;
        G[i].push_back({n, y + x});
        G[n].push_back({i, x});
    }

    vector<ll> dist(n + 1, 1e18);
    priority_queue<P, vector<P>, greater<P>> pq;
    dist[0] = 0;
    pq.push({0, 0});

    while(!pq.empty()){
        auto [c, v] = pq.top(); pq.pop();
        if(dist[v] != c) continue;
        for(auto [nv, nc] : G[v]){
            if(dist[nv] > dist[v] + nc){
                dist[nv] = dist[v] + nc;
                pq.push({dist[nv], nv});
            }
        }
    }

    for(int i = 1; i < n; i++){
        cout << dist[i] << " ";
    }
    cout << endl;
    
    return 0;
}