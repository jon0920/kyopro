#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<tuple<int,int,int>> edges(m);
    rep(i,m){
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u - 1, v - 1, w};
    }

    int ans = 0;
    for(int i = 30; i >= 0; i--){
        dsu uf(n);
        vector<tuple<int,int,int>> next_edges;
        for(auto [u, v, w] : edges){
            if(!((w >> i) & 1)){
                uf.merge(u, v);
                next_edges.push_back({u, v, w});
            }
        }
        if(uf.same(0, n - 1)){
            edges = move(next_edges);
        } else {
            ans |= (1 << i);
        }
    }

    cout << ans << endl;
    
    return 0;
}