#include <bits/stdc++.h>
#include <atcoder/scc>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<pair<int,int>> edges;
        rep(i,n) edges.push_back({i, i});
        rep(i,m){
            int u, v;
            cin >> u >> v;
            u--, v--;
            edges.push_back({u, v});
        }

        int w;
        cin >> w;
        vector<string> s(n);
        rep(i,n) cin >> s[i];

        int v = n * w;
        scc_graph G(v);

        auto ADD_EDGE = [&](int from, int to) -> void {
            rep(i,w){
                if(s[from][i] == 'o' && s[to][(i + 1) % w] == 'o'){
                    G.add_edge(from * w + i, to * w + ((i + 1) % w));
                }
            }
        };

        for(auto [u, v] : edges){
            ADD_EDGE(u, v);
            if(u != v){
                ADD_EDGE(v, u);
            }
        }

        auto scc = G.scc();
        int sz = scc.size();
        bool ok = false;
        rep(i,sz){
            if(scc[i].size() >= 2) ok = true;
        }
        
        cout << (ok ? "Yes" : "No") << endl;
    }
    
    return 0;
}