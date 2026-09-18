#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<ll,ll>;
const ll INF = 1e18;

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<vector<P>> G(n);
    rep(i,m){
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

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

    if(dist[n - 1] >= INF) cout << -1 << endl;
    else cout << dist[n - 1] << endl;
    
    return 0;
}