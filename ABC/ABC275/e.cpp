#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using mint = modint998244353;

int main(){
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<mint>> dp(k + 1, vector<mint>(n + 1, 0));
    dp[0][0] = 1;
    mint m_inv = mint(1) / m;

    rep(i,k){
        for(int j = 0; j <= n; j++){
            if(j == n){
                dp[i + 1][j] += dp[i][j];
            } else {
                for(int x = 1; x <= m; x++){
                    if(j + x <= n) dp[i + 1][j + x] += dp[i][j] * m_inv;
                    else {
                        int d = j + x - n;
                        dp[i + 1][n - d] += dp[i][j] * m_inv;
                    }
                }
            }
        }
    }

    cout << dp[k][n].val() << endl;

    return 0;
}