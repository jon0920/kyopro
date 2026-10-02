#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;
const int INF = 1e9;

struct S{
    int u, v, w;
};

int main(){
    
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<S> edge(m);
    rep(i,m){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edge[i] = {u, v, w};
    }

    vector<pair<int,int>> st(q);
    rep(i,q){
        int s, t;
        cin >> s >> t;
        s--, t--;
        st[i] = {s, t};
    }
    
    int ans = 0;
    for(int bit = 0; bit < (1 << m); bit++){
        if(__builtin_popcount(bit) != k) continue;
        vector<vector<P>> G(n);
        rep(i,m){
            if(!((bit >> i) & 1)){
                int uu = edge[i].u;
                int vv = edge[i].v;
                int ww = edge[i].w;
                G[uu].push_back({vv, ww});
                G[vv].push_back({uu, ww});
            }
        }

        int min_dist = INF;
        for(auto [s, t] : st){
            vector<int> dist(n, INF);
            dist[s] = 0;
            priority_queue<P, vector<P>, greater<P>> pq;
            pq.push({0, s});
            while(!pq.empty()){
                auto [c, v] = pq.top(); pq.pop();
                if(dist[v] != c) continue;
                for(auto [nv, nc] : G[v]){
                    if(dist[nv] <= dist[v] + nc) continue;
                    dist[nv] = dist[v] + nc;
                    pq.push({dist[nv], nv});
                }
            }
            min_dist = min(min_dist, dist[t]);
        }
        ans = max(ans, min_dist);
    }

    if(ans < INF) cout << ans << endl;
    else cout << "INF" << endl;

    return 0;
}