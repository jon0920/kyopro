#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int INF = 1e9;

int main(){

    int n, m, f;
    cin >> n >> m >> f;
    vector<int> r(n);
    rep(i,n) cin >> r[i];
    vector<vector<int>> dist(n, vector<int>(n, INF));
    rep(i,m){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    rep(k,n){
        rep(i,n) rep(j,n) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }

    int ans = -1;
    vector<vector<int>> dp(1 << n, vector<int>(n, -1));
    dp[1][0] = f + r[0];

    for(int i = 0; i < (1 << n); i++){
        for(int j = 0; j < n; j++){
            if(dp[i][j] < 0) continue;
            if(j == n -1){
                ans = max(ans, dp[i][j]);
            }
            for(int k = 0; k < n; k++){
                if((i & (1 << k)) == 0){
                    if(dp[i][j] - dist[j][k] >= 0){
                        dp[i | (1 << k)][k] = max(dp[i | (1 << k)][k], dp[i][j] - dist[j][k] + r[k]);
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}