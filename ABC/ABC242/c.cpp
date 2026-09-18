#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

const ll MOD = 998244353;

int main() {
    
    int n;
    cin >> n;
    vector<vector<ll>> dp(n, vector<ll>(10, 0));
    for(int i = 1; i < 10; i++) dp[0][i] = 1;

    rep(i,n - 1){
        for(int j = 1; j < 10; j++){
            for(int k = -1; k <= 1; k++){
                if(j + k <= 0 || j + k >= 10) continue;
                dp[i + 1][j + k] += dp[i][j];
                dp[i + 1][j + k] %= MOD;
            }
        }
    }

    ll ans = 0;
    for(int i = 1; i < 10; i++){
        ans += dp[n - 1][i];
        ans %= MOD;
    }
    cout << ans << endl;
    
    return 0;
}