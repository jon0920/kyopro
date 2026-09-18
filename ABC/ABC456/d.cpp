#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using mint = modint998244353;

int main(){

    string s;
    cin >> s;
    int n = s.size();
    vector<vector<mint>> dp(n + 1, vector<mint>(3));
    rep(i,n){
        int v = s[i] - 'a';
        rep(j,3){
            if(v == j){
                dp[i + 1][j] = dp[i][0] + dp[i][1] + dp[i][2] + 1;
            } else {
                dp[i + 1][j] = dp[i][j];
            }
        }
    }

    mint ans = 0;
    rep(i,3) ans += dp[n][i];
    cout << ans.val() << endl;

    return 0;
}