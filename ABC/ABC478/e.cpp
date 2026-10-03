#include <bits/stdc++.h>
#include <atcoder/scc>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;

    scc_graph G(n);
    vector<tuple<int,int,int>> edge(q);
    rep(i,q){
        int t, u, v;
        cin >> t >> u >> v;
        u--, v--;
        if(t == 0){
            edge[i] = {u, v, 0};
        } else {
            edge[i] = {u, v, 1};
        }
        G.add_edge(u, v);
    }

    auto scc = G.scc();
    int sz = scc.size();
    vector<int> group(n);
    rep(i,sz){
        for(int v : scc[i]) group[v] = i;
    }

    vector<vector<pair<int,int>>> DAG(sz);
    vector<int> deg(sz);

    for(auto [u, v, t] : edge){
        if(group[u] == group[v]){
            if(t == 1){
                cout << "No" << endl;
                return 0;
            }
        } else {
            DAG[group[u]].push_back({group[v], t});
            deg[group[v]]++;
        }
    }

    queue<int> que;
    rep(i,sz) if(deg[i] == 0) que.push(i);
    vector<int> max_dist(sz, 1);
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(auto [nv, nt] : DAG[v]){
            max_dist[nv] = max(max_dist[nv], max_dist[v] + nt);
            deg[nv]--;
            if(deg[nv] == 0) que.push(nv);
        }
    }
    
    cout << "Yes" << endl;
    rep(i,n){
        cout << max_dist[group[i]] << " ";
    }
    cout << endl;
    
    return 0;
}