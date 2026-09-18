#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<ll> a(n + 2), b(n + 2);
    for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    
    vector<vector<vector<ll>>> dp(n + 2, vector<vector<ll>>(2 * k + 1, vector<ll>(2, -INF)));
    dp[0][0][0] = 0;

    for(int i = 1; i <= n + 1; i++){
        for(int j = 0; j <= 2 * k; j++){
            rep(prev_state,2){
                if(dp[i - 1][j][prev_state] == -INF) continue;

                rep(crr_state,2){
                    if(i == n + 1 && crr_state == 1) continue;

                    int nj = j + (prev_state != crr_state);
                    if(nj > 2 * k) continue;

                    ll val = (crr_state == 0 ? a[i] : b[i]);
                    dp[i][nj][crr_state] = max(dp[i][nj][crr_state], dp[i - 1][j][prev_state] + val);
                }
            }
        }
    }

    ll ans = 0;
    for(int i = 0; i <= 2 * k; i++){
        ans = max(ans, dp[n + 1][i][0]);
    }

    cout << ans << endl;
    
    return 0;
}