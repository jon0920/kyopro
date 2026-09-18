#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
const int INF = 1e9;

int main(){
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    vector<pair<int,int>> edges(m);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[i] = {u, v};
    }

    auto solve = [&](int x){
        vector<vector<int>> G(n);
        for(auto [u, v] : edges){
            if(max(h[u], h[v]) <= x){
                G[u].push_back(v);
                G[v].push_back(u);
            }
        }
        vector<int> dist(n, INF);
        queue<int> que;
        dist[0] = 1;
        que.push(0);
        while(!que.empty()){
            int v = que.front(); que.pop();
            for(auto nv : G[v]){
                if(dist[nv] == INF){
                    dist[nv] = dist[v] + 1;
                    que.push(nv);
                }
            }
        }
        return dist[n - 1] <= k;
    };

    int ok = 1e9 + 1, ng = 0;
    while(ok - ng > 1){
        int mid = (ok + ng) / 2;
        if(solve(mid)) ok = mid;
        else ng = mid;
    }

    if(ok > INF) cout << -1 << endl;
    else cout << ok << endl;
    
    return 0;
}