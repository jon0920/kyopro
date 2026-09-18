#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> edge_cnt(n);
    dsu uf(n);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        if(uf.same(u,v)){
            edge_cnt[uf.leader(u)]++;
        } else {
            int U = edge_cnt[uf.leader(u)];
            int V = edge_cnt[uf.leader(v)];
            uf.merge(u,v);
            edge_cnt[uf.leader(u)] = U + V + 1;
        }
    }
    
    bool ans = true;
    rep(i,n){
        if(uf.leader(i) == i){
            if(uf.size(i) != edge_cnt[i]) ans = false;
        }
    }

    cout << (ans ? "Yes" : "No") << endl;
    
    return 0;
}