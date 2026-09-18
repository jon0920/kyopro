#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using P = pair<int,int>;

int main(){
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<P>> G(n * 2);
    rep(i,m){
        int u, v, a;
        cin >> u >> v >> a;
        u--, v--;
        if(a == 1){
            G[u].push_back({v, 1});
            G[v].push_back({u, 1});
        } else {
            G[u + n].push_back({v + n, 1});
            G[v + n].push_back({u + n, 1});
        }
    }

    rep(i,k){
        int s;
        cin >> s;
        s--;
        G[s].push_back({s + n, 0});
        G[s + n].push_back({s, 0});
    }

    vector<int> dist(n * 2, 1e9);
    dist[0] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 0});
    while(!pq.empty()){
        auto [c, v] = pq.top(); pq.pop();
        if(dist[v] != c) continue;
        for(auto [nv, nc] : G[v]){
            if(dist[nv] <= dist[v] + nc) continue;
            dist[nv] = dist[v] + nc;
            pq.push({dist[nv], nv});
        }
    }

    if(dist[n - 1] == 1e9 && dist[n * 2 - 1] == 1e9) cout << -1 << endl;
    else cout << min(dist[n - 1], dist[n * 2 - 1]) << endl;
    
    return 0;
}