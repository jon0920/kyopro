#include <bits/stdc++.h>
#include <atcoder/maxflow>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> color(n, -1);
    rep(i,n){
        if(color[i] == -1){
            queue<int> que;
            que.push(i);
            color[i] = 0;
            while(!que.empty()){
                int v = que.front(); que.pop();
                for(int nv : G[v]){
                    if(color[nv] == -1){
                        color[nv] = color[v] ^ 1;
                        que.push(nv);
                    }
                }
            }
        }
    }

    mf_graph<int> g(n + 2);
    rep(v,n){
        if(color[v] == 0){
            g.add_edge(n, v, 1);
            for(int nv : G[v]){
                g.add_edge(v, nv, 1);
            }
        } else {
            g.add_edge(v, n + 1, 1);
        }
    }

    cout << g.flow(n, n + 1) << endl;
    
    return 0;
}