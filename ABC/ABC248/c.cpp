#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using mint = atcoder::modint998244353;

int main(){
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<mint>> dp(n + 1, vector<mint>(k + 1));
    dp[0][0] = 1;

    rep(i,n){
        rep(j,k){
            if(dp[i][j] == 0) continue;
            for(int x = 1; x <= m; x++){
                if(j + x <= k){
                    dp[i + 1][j + x] += dp[i][j];
                }
            }
        }
    }

    mint ans = 0;
    rep(i,k + 1) ans += dp[n][i];

    cout << ans.val() << endl;
    
    return 0;
}