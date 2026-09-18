#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using mint = modint1000000007;

int main(){
    
    string l;
    cin >> l;
    int n = l.size();

    vector<vector<mint>> dp(n + 1, vector<mint>(2, 0));
    dp[0][0] = 1;

    rep(i,n){
        dp[i + 1][1] += dp[i][1] * 3;
        
        if(l[i] == '0'){
            dp[i + 1][0] += dp[i][0];
        } else {
            dp[i + 1][1] += dp[i][0];
            dp[i + 1][0] += dp[i][0] * 2;
        }
    }

    mint ans = dp[n][0] + dp[n][1];
    cout << ans.val() << endl;
    
    return 0;
}