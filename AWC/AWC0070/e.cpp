#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;
using P = pair<ll,ll>;

int main(){
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(k);
    rep(i,k) cin >> v[i], v[i]--;
    k += 1;
    v.insert(v.begin(), 0);
    vector<vector<P>> G(n);
    rep(i,m){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--, b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    auto dijkstra = [&](int x){
        vector<ll> d(n, INF);
        d[x] = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, x});
        while(!pq.empty()){
            auto [cost, now] = pq.top(); pq.pop();
            if(cost != d[now]) continue;
            for(auto [to, nc] : G[now]){
                if(d[to] > d[now] + nc){
                    d[to] = d[now] + nc;
                    pq.push({d[to], to});
                }
            }
        }
        return d;
    };

    auto TSP = [&](vector<vector<ll>> a){
        int sz = a.size();
        vector<vector<ll>> d(sz, vector<ll>(1<<sz, INF));
        d[0][1] = 0;
        for(int x = 0; x < (1 << sz); x++){
            rep(i,sz){
                if(d[i][x] == INF) continue;
                ll dix = d[i][x];
                rep(j,sz){
                    int y = x | (1 << j);
                    if(x == y) continue;
                    ll nd = dix + a[i][j];
                    if(nd < d[j][y]) d[j][y] = nd;
                }
            }
        }
        ll ans = INF;
        rep(i,sz) ans = min(ans, d[i][(1 << sz) - 1] + a[i][0]);
        return ans;
    };

    vector<vector<ll>> dist(k, vector<ll>(k, 0));
    rep(st,k){
        vector<ll> dd = dijkstra(v[st]);
        rep(i,k) dist[st][i] = dd[v[i]];
    }

    cout << TSP(dist) << endl;
    
    return 0;
}