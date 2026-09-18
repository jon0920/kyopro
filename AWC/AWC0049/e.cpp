#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); i++)

const ll INF = 4e18;

int main(){

    int n;
    cin >> n;
    vector<ll> v(n);
    rep(i,n) cin >> v[i];

    vector<vector<ll>> dp(1 << n, vector<ll>(n, INF));
    dp[1][0] = 0;

    for(ll s = 0; s < (1 << n); s++){
        rep(i,n){
            if(((s >> i) & 1) == 0) continue;
            if(dp[s][i] == INF) continue;
            rep(j,n){
                if(((s >> j) & 1) == 0){
                    ll ns = s | (1 << j);
                    ll cost = abs(v[i] - v[j]) * abs(i - j);
                    if(dp[ns][j] > dp[s][i] + cost){
                        dp[ns][j] = dp[s][i] + cost;
                    }
                }
            }
        }
    }

    ll ans = INF;
    rep(i,n){
        ans = min(ans, dp[(1 << n) - 1][i]);
    }

    cout << ans << endl;

    return 0;
}