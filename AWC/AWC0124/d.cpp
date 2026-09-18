#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, -1));
    dp[0][0] = 0;
    rep(i,n){
        ll w, s;
        cin >> w >> s;
        rep(j,k + 1){
            if(dp[i][j] == -1) continue;
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            dp[i + 1][min(j + w, (ll)k)] = max(dp[i + 1][min(j + 1, (ll)k)], dp[i][j] + s);
        }
    }

    cout << dp[n][k] << endl;
    
    return 0;
}