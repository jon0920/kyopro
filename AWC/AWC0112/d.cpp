#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<vector<ll>> dp(k + 1, vector<ll>(2, -INF));
    dp[0][0] = 0;

    rep(i,n){
        vector<vector<ll>> ndp(k + 1, vector<ll>(2, -INF));
        ll v; int w;
        cin >> v >> w;
        rep(j,k + 1){
            ndp[j][0] = max(ndp[j][0], max(dp[j][0], dp[j][1]));
            if(j + w <= k) ndp[j + w][1] = max(ndp[j + w][1], dp[j][0] + v);
        }
        dp = ndp;
    }

    ll ans = -INF;
    rep(i,k + 1) ans = max(ans, max(dp[i][0], dp[i][1]));

    cout << ans << endl;
    
    return 0;
}