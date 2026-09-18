#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using P = pair<ll,ll>;
const ll INF = 4e18;

int main(){

    ll n, m, x;
    cin >> n >> m >> x;
    vector<vector<P>> G(2 * n);
    rep(i,n){
        G[i].push_back({n + i, x});
        G[n + i].push_back({i, x});
    }
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back({v, 1});
        G[v + n].push_back({u + n, 1});
    }

    vector<ll> dist(2 * n, INF);
    dist[0] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 0});

    while(!pq.empty()){
        auto [c, v] = pq.top(); pq.pop();
        if(dist[v] < c) continue;

        for(auto [nv, nc] : G[v]){
            if(dist[nv] > dist[v] + nc){
                dist[nv] = dist[v] + nc;
                pq.push({dist[nv], nv});
            }
        }
    }

    cout << min(dist[n - 1], dist[2 * n - 1]) << endl;

    return 0;
}