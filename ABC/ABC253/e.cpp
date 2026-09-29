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

    vector<mint> dp(m, 1);

    rep(i,n - 1){
        vector<mint> ndp(m);
        vector<mint> imos(m + 1);
        rep(j,m){
            if(k == 0){
                imos[0] += dp[j];
                imos[m] -= dp[j];
            } else {
                if(j - k >= 0){
                    imos[0] += dp[j];
                    imos[j - k + 1] -= dp[j];
                }
                if(j + k <= m){
                    imos[j + k] += dp[j];
                    imos[m] -= dp[j];
                }
            }
        }
        rep(i,m) imos[i + 1] += imos[i];
        rep(i,m) ndp[i] = imos[i];
        dp = ndp;
    }

    mint ans = 0;
    rep(i,m) ans += dp[i];
    cout << ans.val() << endl;
    
    return 0;
}