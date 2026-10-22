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
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    int k, T;
    cin >> k >> T;
    vector<bool> airport(n);
    rep(i,k){
        int d;
        cin >> d;
        d--;
        airport[d] = true;
    }

    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    vector<ll> airport_dist(n, INF);
    
    auto calc_airport_dist = [&]() -> void {
        fill(airport_dist.begin(), airport_dist.end(), INF);
        rep(i,n){
            rep(j,n){
                if(airport[j]){
                    airport_dist[i] = min(airport_dist[i], dist[i][j]);
                }
            }
        }
    };
    
    rep(i,n){
        dist[i][i] = 0;
        if(airport[i]) airport_dist[i] = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, i});
        while(!pq.empty()){
            auto [c, v] = pq.top(); pq.pop();
            if(dist[i][v] != c) continue;
            for(auto [nv, nc] : G[v]){
                if(dist[i][nv] <= dist[i][v] + nc) continue;
                dist[i][nv] = dist[i][v] + nc;
                pq.push({dist[i][nv], nv});
            }
        }
    }

    calc_airport_dist();

    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int x, y; ll t;
            cin >> x >> y >> t;
            x--, y--;
            rep(i,n){
                rep(j,n){
                    dist[i][j] = min({dist[i][j], dist[i][x] + dist[y][j] + t, dist[i][y] + dist[x][j] + t});
                }
            }
            calc_airport_dist();
        } else if(type == 2){
            int x;
            cin >> x;
            x--;
            if(airport[x]) continue;
            airport[x] = true;
            calc_airport_dist();
        } else {
            ll res = 0;
            rep(i,n){
                rep(j,n){
                    ll d = min(dist[i][j], airport_dist[i] + airport_dist[j] + T);
                    if(d < INF) res += d;
                }
            }
            cout << res << "\n";
        }
    }
    
    return 0;
}