#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using mint = modint998244353;

int main(){

    int n, m;
    cin >> n >> m;
    int sz = min(n, m);
    vector<mint> dp(sz + 1);
    dp[0] = 1;
    rep(i,n){
        ll d;
        cin >> d;
        vector<mint> ep(sz + 1);
        rep(j,sz + 1){
            if(d == 0){
                ep[j] += dp[j] * j;
                if(j != sz){
                    ep[j + 1] += dp[j] * (m - j);
                }
            }
            else if(d <= j){
                ep[j] += dp[j];
            }
            else if(d == j + 1){
                if(j != sz) ep[j + 1] += dp[j] * (m - j);
            }
        }
        dp = ep;
    }

    mint ans = 0;
    for(auto &x : dp) ans += x;
    cout << ans.val() << endl;

    return 0;
}