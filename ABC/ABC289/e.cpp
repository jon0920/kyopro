#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> c(n);
        rep(i,n) cin >> c[i];
        vector<vector<int>> G(n);
        rep(i,m){
            int u, v;
            cin >> u >> v;
            u--, v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        if(c[0] == c[n - 1]){
            cout << -1 << endl;
            continue;
        }

        vector<vector<int>> dist(n, vector<int>(n, -1));
        dist[0][n - 1] = 0;
        queue<pair<int,int>> que;
        que.push({0, n - 1});

        while(!que.empty()){
            auto [u, v] = que.front(); que.pop();
            for(int nu : G[u]){
                for(int nv : G[v]){
                    if(dist[nu][nv] == -1 && c[nu] != c[nv]){
                        dist[nu][nv] = dist[u][v] + 1;
                        que.push({nu, nv});
                    }
                }
            }
        }

        if(dist[n - 1][0] == -1) cout << -1 << endl;
        else cout << dist[n - 1][0] << endl;
    }
    
    return 0;
}