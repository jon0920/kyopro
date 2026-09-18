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
    vector<mint> dp(k + 1);
    dp[0] = 1;

    rep(i,n){
        int p;
        cin >> p;
        vector<mint> ndp(k + 1);
        rep(j,k + 1){
            if(dp[j] == 0) continue;
            ndp[j] += dp[j];
            if(j + p <= k) ndp[j + p] += dp[j];
        }
        dp = ndp;
    }

    cout << dp[k].val() << endl;
    
    return 0;
}