#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){

    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, INF));
    for(int i = 1; i <= n; i++) dist[i][i] = 0;
    rep(i,m){
        ll u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
    }

    for(ll k = 1; k <= n; k++){
        for(ll i = 1; i <= n; i++){
            for(ll j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    ll s, k;
    cin >> s >> k;
    vector<ll> t(k);
    rep(i,k) cin >> t[i];

    vector<vector<ll>> dp(1LL << k, vector<ll>(k, INF));
    rep(i,k) dp[(1LL << i)][i] = dist[s][t[i]];

    for(ll i = 0; i < (1LL << k); i++){
        rep(j,k){
            if(dp[i][j] >= INF) continue;
            rep(p,k){
                if(i & (1LL << p)) continue;
                dp[i | (1LL << p)][p] = min(dp[i | (1LL << p)][p], dp[i][j] + dist[t[j]][t[p]]);
            }
        }
    }

    ll ans = INF;
    rep(i,k) ans = min(ans, dp[(1LL << k) - 1][i] + dist[t[i]][s]);
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}