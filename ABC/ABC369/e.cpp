#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    rep(i,n) dist[i][i] = 0;
    vector<tuple<int,int,int>> bridges(m);
    rep(i,m){
        ll u, v, t;
        cin >> u >> v >> t;
        u--, v--;
        dist[u][v] = min(dist[u][v], t);
        dist[v][u] = min(dist[v][u], t);
        bridges[i] = {u, v, t};
    }

    rep(k,n){
        rep(i,n){
            rep(j,n){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
;            }
        }
    }

    int q;
    cin >> q;
    while(q--){
        int k;
        cin >> k;
        vector<ll> bu(k), bv(k), bt(k);
        rep(i,k){
            int b;
            cin >> b;
            b--;
            auto [u, v, t] = bridges[b];
            bu[i] = u, bv[i] = v, bt[i] = t;
        }

        vector<vector<vector<ll>>> dp(1 << k, vector<vector<ll>>(k, vector<ll>(2, INF)));
        rep(i,k){
            dp[1 << i][i][0] = dist[0][bv[i]] + bt[i];
            dp[1 << i][i][1] = dist[0][bu[i]] + bt[i];
        }

        for(int mask = 0; mask < (1 << k); mask++){
            rep(i,k){
                rep(p,2){
                    if(dp[mask][i][p] == INF) continue;
                    int cur = (p == 0 ? bu[i] : bv[i]);
                    rep(j,k){
                        if((mask >> j) & 1) continue;
                        int next_mask = mask | (1 << j);

                        dp[next_mask][j][0] = min(dp[next_mask][j][0], dp[mask][i][p] + dist[cur][bv[j]] + bt[j]);
                        dp[next_mask][j][1] = min(dp[next_mask][j][1], dp[mask][i][p] + dist[cur][bu[j]] + bt[j]);
                    }
                }
            }
        }

        ll ans = INF;
        rep(i,k){
            rep(p,2){
                int cur = (p == 0 ? bu[i] : bv[i]);
                ans = min(ans, dp[(1 << k) - 1][i][p] + dist[cur][n - 1]);
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}