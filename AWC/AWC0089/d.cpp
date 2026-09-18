#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<ll,ll>;

const ll INF = 1e18;

int main(){
    
    ll n, k, p;
    cin >> n >> k >> p;
    vector<ll> m(n);
    rep(i,n) cin >> m[i];
    vector<vector<P>> G(n);
    rep(i,k){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back({v, m[u] * m[v]});
        G[v].push_back({u, m[u] * m[v]});
    }

    vector<int> e(p);
    rep(i,p) cin >> e[i], e[i]--;

    vector<ll> dist(n, INF);
    dist[0] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
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

    ll ans = INF;
    for(auto x : e) ans = min(ans, dist[x]);
    cout << ans << endl;
    
    return 0;
}