#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){
    
    int n, s, t;
    cin >> n >> s >> t;
    vector<int> c(n), v(n);
    rep(i,n) cin >> c[i] >> v[i];

    int lim = s - t;
    if(lim <= 0){
        cout << 0 << endl;
        return 0;
    }

    vector<ll> dp(lim + 1, -INF);
    dp[0] = 0;
    rep(i,n){
        vector<ll> ep(lim + 1, -INF);
        rep(j,lim + 1){
            if(dp[j] == INF) continue;
            ep[j] = max(ep[j], dp[j]);
            if(j + c[i] <= lim){
                ep[j + c[i]] = max(ep[j + c[i]], dp[j] + v[i]);
            }
        }
        dp = ep;
    }

    ll ans = -INF;
    rep(i,lim + 1) ans = max(ans, dp[i]);
    cout << ans << endl;
    
    return 0;
}