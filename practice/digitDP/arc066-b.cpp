#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using mint = modint1000000007;

int main(){
    
    ll n;
    cin >> n;

    vector<mint> dp(3, 0);
    dp[0] = 1;

    rep(i,62){
        int d = 1 & (n >> (61 - i));
        vector<mint> ndp(3, 0);

        rep(j,3){
            if(dp[j].val() == 0) continue;

            rep(v,3){
                int nv = 2 * j + d - v;
                if(nv < 0) continue;

                int nj = min(nv, 2);
                ndp[nj] += dp[j];
            }
        }
        dp = move(ndp);
    }

    mint ans = dp[0] + dp[1] + dp[2];
    cout << ans.val() << endl;
    
    return 0;
}