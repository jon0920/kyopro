#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;
const int INF = 1e9;

int main(){

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> G(n);
    vector<int> deg(n, 0);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    vector<int> dist(n, INF);
    dist[0] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 0});

    while(!pq.empty()){
        auto [d, v] = pq.top(); pq.pop();
        if(dist[v] != d) continue;
        for(auto nv : G[v]){
            int cost = 1;
            if(nv != n - 1 && deg[nv] >= k) cost++;
            if(dist[nv] > dist[v] + cost){
                dist[nv] = dist[v] + cost;
                pq.push({dist[nv], nv});
            }
        }
    }

    if(dist[n - 1] == INF) cout << -1 << endl;
    else cout << dist[n - 1] << endl;

    return 0;
}