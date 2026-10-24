#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k, c;
    cin >> n >> k >> c;

    ll dp[n + 1][k + 1][c + 1];
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;

    rep(i,n){
        ll w, v;
        cin >> w >> v;
        rep(j,k + 1){
            rep(l,c + 1){
                if(dp[i][j][l] == -1) continue;
                dp[i + 1][j][l] = max(dp[i + 1][j][l], dp[i][j][l]);
                if(j + 1 <= k && l + w <= c){
                    dp[i + 1][j + 1][l + w] = max(dp[i + 1][j + 1][l + w], dp[i][j][l] + v);
                }
            }
        }
    }

    ll ans = 0;
    rep(j,k + 1){
        rep(l,c + 1) ans = max(ans, dp[n][j][l]);
    }
    cout << ans << endl;
    
    return 0;
}