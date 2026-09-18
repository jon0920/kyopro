#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){
    
    int n, c, K;
    cin >> n >> c >> K;
    vector<ll> b(n), w(n);
    rep(i,n) cin >> b[i] >> w[i];

    vector<vector<ll>> dp(c + 1, vector<ll>(K + 1, -INF));
    dp[0][0] = 0;

    rep(i,n){
        vector<vector<ll>> ndp = dp;
        rep(j,c + 1){
            rep(k,K + 1){
                if(dp[j][k] == -INF) continue;

                ndp[j][k] = max(ndp[j][k], dp[j][k]);

                int x = j + w[i];
                int y = j + (w[i] / 2);

                if(x <= c) ndp[x][k] = max(ndp[x][k], dp[j][k] + b[i]);
                if(y <= c && k != K) ndp[y][k + 1] = max(ndp[y][k + 1], dp[j][k] + b[i]);
            }
        }
        dp = ndp;
    }

    ll ans = -INF;
    rep(j, c + 1){
        rep(k,K + 1){
            ans = max(ans, dp[j][k]);
        }
    }

    cout << ans << endl;
    
    return 0;
}