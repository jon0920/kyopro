#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using mint = modint1000000007;

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
        a[i] %= k;
    }

    vector<vector<mint>> dp(n + 1, vector<mint>(k + 1));
    dp[0][0] = 1;

    rep(i,n){
        rep(j,k + 1){
            if(dp[i][j] == 0) continue;
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][(j + a[i]) % k] += dp[i][j];
        }
    }
    mint ans = dp[n][0] - 1;
    cout << ans.val() << endl;
    
    return 0;
}