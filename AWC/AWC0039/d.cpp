#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using pll = pair<ll,ll>;
const ll INF = 4e18;

int main(){

    int n, m;
    cin >> n >> m;
    vector<vector<pair<ll,ll>>> G(n);
    rep(i,m){
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        G[u].push_back({v, c});
    }

    vector<ll> dist(n, INF);
    dist[0] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0,0});

    while(!pq.empty()){
        auto [d, v] = pq.top(); pq.pop();
        if(dist[v] < d) continue;
        for(auto [nv, c] : G[v]){
            if(dist[v] + c >= dist[nv]) continue;
            dist[nv] = dist[v] + c;
            pq.push({dist[nv], nv});
        }
    }

    cout << dist[n - 1] << endl;

    return 0;
}