#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){
    
    ll n, m, k, b;
    cin >> n >> m >> k >> b;
    vector<tuple<ll,ll,ll>> dvt(n);
    rep(i,n){
        ll d, v, t;
        cin >> d >> v >> t;
        dvt[i] = {d, v, t};
    }
    sort(dvt.begin(), dvt.end(), [](const auto &x, const auto &y){
        auto [d1, v1, t1] = x;
        auto [d2, v2, t2] = y;
        return t1 < t2;
    });

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -INF));
    dp[0][0] = 0;

    rep(i,n){
        auto [D, V, T] = dvt[i];
        for(int j = i; j >= 0; j--){
            for(int t = 0; t <= T - D; t++){
                dp[j + 1][t + D] = max(dp[j + 1][t + D], dp[j][t] + V);
            }
        }
    }
    
    ll ans = 0;
    for(int i = 0; i <= n; i++){
        for(int t = 0; t <= m; t++){
            ans = max(ans, dp[i][t] + (i >= k ? b : 0));
        }
    }
    cout << ans << endl;

    return 0;
}