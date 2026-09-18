#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int INF = 1e9;

int main(){

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> G(n);
    rep(i,m){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        if(w >= k){
            G[u].push_back(v);
            G[v].push_back(u);
        }
    }

    vector<int> dist(n, INF);
    dist[0] = 0;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(auto nv : G[v]){
            if(dist[nv] != INF) continue;
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

    if(dist[n - 1] == INF) cout << -1 << endl;
    else cout << dist[n - 1] << endl;

    return 0;
}