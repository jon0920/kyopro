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
        int u, v, c;
        cin >> u >> v >> c;
        edges[i] = {c, u - 1, v - 1};
    }

    sort(edges.begin(), edges.end());
    
    dsu uf(n);
    ll ans = 0;
    for(auto [c, u, v] : edges){
        if(!uf.same(u, v)){
            ans += c;
            uf.merge(u, v);
        }
    }

    cout << ans << endl;
    
    return 0;
}