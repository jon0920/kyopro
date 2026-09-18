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
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    int s, k;
    cin >> s >> k;
    s--;
    vector<int> d(k + 1);
    d[0] = s;
    for(int i = 1; i <= k; i++) cin >> d[i], d[i]--;

    auto dijkstra = [&](int x) -> vector<ll> {
        vector<ll> dist(n, INF);
        dist[x] = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, x});
        while(!pq.empty()){
            auto [d, v] = pq.top(); pq.pop();
            if(dist[v] != d) continue;
            for(auto [nv, nd] : G[v]){
                if(dist[nv] <= dist[v] + nd) continue;
                dist[nv] = dist[v] + nd;
                pq.push({dist[nv], nv});
            }
        }
        return dist;
    };

    k++;
    vector<vector<ll>> dist(k, vector<ll>(k));
    rep(i,k){
        vector<ll> tmp = dijkstra(d[i]);
        rep(j,k){
            dist[i][j] = tmp[d[j]];
        }
    }

    vector<vector<ll>> dp((1 << k), vector<ll>(k, INF));
    dp[0][0] = 0;
    for(int bit = 0; bit < (1 << k); bit++){
        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++){
                dp[bit | (1 << j)][j] = min(dp[bit | (1 << j)][j], dp[bit][i] + dist[i][j]);
            }
        }
    }

    cout << dp[(1 << k) - 1][0] << endl;

    return 0;
}