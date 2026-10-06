#include <bits/stdc++.h>
#include <atcoder/scc>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct S{
    int t, u, v;
};

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<S> edges(q);
    scc_graph G(n);
    rep(i,q){
        int t, u, v;
        cin >> t >> u >> v;
        u--, v--;
        edges[i] = {t, u, v};
        G.add_edge(u, v);
    }

    auto SCC = G.scc();
    int sz = SCC.size();
    vector<int> group(n);
    rep(i,sz){
        for(int x : SCC[i]){
            group[x] = i;
        }
    }
    
    vector<vector<pair<int,int>>> GG(sz);
    vector<int> deg(sz);
    for(auto [t, u, v] : edges){
        if(group[u] == group[v]){
            if(t == 1){
                cout << "No" << endl;
                return 0;
            }
        } else {
            GG[group[u]].push_back({group[v], t});
            deg[group[v]]++;
        }
    }

    queue<int> que;
    vector<int> ans(n, 1);
    rep(i,sz){
        if(deg[i] == 0){
            que.push(i);
        }
    }

    while(!que.empty()){
        int x = que.front(); que.pop();
        for(auto [nx, t] : GG[x]){
            ans[nx] = max(ans[nx], ans[x] + t);
            deg[nx]--;
            if(deg[nx] == 0) que.push(nx);
        }
    }

    cout << "Yes" << endl;
    rep(i,n) cout << ans[group[i]] << " ";
    cout << endl;
    
    return 0;
}