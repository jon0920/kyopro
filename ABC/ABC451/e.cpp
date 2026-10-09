#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<vector<int>> a(n - 1, vector<int>(n));
    vector<tuple<int,int,int>> edges;
    rep(i,n - 1){
        for(int j = i + 1; j < n; j++){
            cin >> a[i][j];
            edges.push_back({a[i][j], i, j});
        }
    }
    sort(edges.begin(), edges.end());

    dsu uf(n);
    vector<vector<pair<int,int>>> G(n);
    for(auto [w, u, v] : edges){
        if(!uf.same(u, v)){
            uf.merge(u, v);
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
    }

    bool ans = true;
    auto dfs = [&](auto dfs, int init, int v, int parent, int dist) -> void {
        if(init < v && a[init][v] != dist) ans = false;
        for(auto [nv, w] : G[v]){
            if(nv == parent) continue;
            dfs(dfs, init, nv, v, dist + w);
        }
    };

    rep(i,n) dfs(dfs, i, i, -1, 0);
    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}