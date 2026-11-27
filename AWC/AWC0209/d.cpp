#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using mint = modint998244353;

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<vector<int>> ab(n, vector<int>(2));
    rep(i,n) cin >> ab[i][0] >> ab[i][1];

    vector<vector<vector<mint>>> dp(n, vector<vector<mint>>(k + 1, vector<mint>(2)));
    dp[0][0][0] = 1;
    dp[0][0][1] = 1;
    for(int i = 1; i < n; i++){
        rep(j,k + 1){
            rep(p,2){
                rep(q,2){
                    if(ab[i][p] == ab[i - 1][q]){
                        if(j + 1 <= k){
                            dp[i][j + 1][p] += dp[i - 1][j][q];
                        }
                    } else {
                        dp[i][j][p] += dp[i - 1][j][q];
                    }
                }
            }
        }
    }

    mint ans = dp[n - 1][k][0] + dp[n - 1][k][1];
    cout << ans.val() << endl;
    
    return 0;
}