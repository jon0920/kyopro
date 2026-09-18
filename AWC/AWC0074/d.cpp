#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<ll,ll>;

const ll INF = 1e18;

int main(){
    
    int n, m, s, t, p;
    cin >> n >> m >> s >> t >> p;
    s--, t--, p--;
    vector<vector<P>> G(n);
    rep(i,m){
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    vector<ll> dist(n, INF);
    dist[p] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, p});
    while(!pq.empty()){
        auto [cost, v] = pq.top(); pq.pop();
        if(dist[v] != cost) continue;
        for(auto [nv, nc] : G[v]){
            if(dist[nv] > dist[v] + nc){
                dist[nv] = dist[v] + nc;
                pq.push({dist[nv], nv});
            }
        }
    }

    vector<ll> safe(n, -1);
    priority_queue<P> pq2;
    safe[s] = dist[s];
    pq2.push({safe[s], s});

    while(!pq2.empty()){
        auto [crr, v] = pq2.top(); pq2.pop();
        if(safe[v] != crr) continue;
        for(auto [nv, _] : G[v]){
            ll nxt = min(crr, dist[nv]);
            if(safe[nv] < nxt){
                safe[nv] = nxt;
                pq2.push({safe[nv], nv});
            }
        }
    }

    ll ans = safe[t];
    if(ans >= INF) cout << "INF" << endl;
    else cout << ans << endl;
    
    return 0;
}