#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using P = pair<ll,ll>;
const ll INF = 1e18;

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<vector<P>> G(n);
    rep(i,m){
        ll l, r, d;
        cin >> l >> r >> d;
        l--, r--;
        G[l].push_back({r, d});
        G[r].push_back({l, -d});
    }

    vector<ll> dist(n, INF);
    bool ok = true;
    rep(i,n){
        if(dist[i] == INF){
            queue<P> que;
            que.push({i, 0});
            dist[i] = 0;
            while(!que.empty()){
                auto [v, d] = que.front(); que.pop();
                for(auto [nv, nd] : G[v]){
                    if(dist[nv] == INF){
                        dist[nv] = dist[v] + nd;
                        que.push({nv, dist[nv]});
                    } else {
                        if(dist[nv] != dist[v] + nd){
                            ok = false;
                        }
                    }
                }
            }
        }
    }

    cout << (ok ? "Yes" : "No") << endl;
    
    return 0;
}