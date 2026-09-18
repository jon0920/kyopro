#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<ll,ll>;

int main(){
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];
    vector<vector<P>> G(n);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back({v, abs(h[u] - h[v])});
        G[v].push_back({u, abs(h[u] - h[v])});
    }

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 0});
    vector<ll> dist(n, 1e18);
    dist[0] = 0;

    while(!pq.empty()){
        auto [c, v] = pq.top(); pq.pop();
        if(c != dist[v]) continue;
        for(auto [nv, nc] : G[v]){
            if(dist[nv] <= dist[v] + nc) continue;
            if(nc > k) continue;
            dist[nv] = dist[v] + nc;
            pq.push({dist[nv], nv});
        }
    }

    cout << (dist[n - 1] == 1e18 ? -1 : dist[n - 1]) << endl;
    
    return 0;
}