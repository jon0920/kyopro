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
    vector<mint> dp(k, 0);
    dp[0] = 1;

    vector<mint> ndp(k);
    rep(i,n){
        int a;
        cin >> a;
        int ar = a % k;
        ndp = dp;
        rep(r,k){
            if(dp[r].val() == 0) continue;
            int nr = (r + ar) % k;
            ndp[nr] += dp[r];
        }
        dp = ndp;
    }

    mint ans = dp[0] - 1;
    cout << ans.val() << endl;
    
    return 0;
}