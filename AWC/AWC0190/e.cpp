#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){
    
    int n, k, W;
    cin >> n >> k >> W;
    vector<vector<ll>> dp(1 << k, vector<ll>(W + 1, -INF));
    dp[0][0] = 0;

    rep(i,n){
        ll w, v, d;
        cin >> w >> v >> d;
        d--;
        vector<vector<ll>> ndp(1 << k, vector<ll>(W + 1, -INF));
        rep(mask,1<<k){
            rep(j, W + 1){
                if(dp[mask][j] == -INF) continue;

                ndp[mask][j] = max(ndp[mask][j], dp[mask][j]);

                if(j + w <= W){
                    ll next_mask = mask | (1 << d);
                    ndp[next_mask][j + w] = max(ndp[next_mask][j + w], dp[mask][j] + v);
                }
            }
        }
        dp = move(ndp);
    }

    ll ans = 0;
    rep(mask,1<<k){
        ll p = __builtin_popcount(mask);
        rep(j,W + 1){
            ans = max(ans, dp[mask][j] - p * p);
        }
    }

    cout << ans << endl;
    
    return 0;
}