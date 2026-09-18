#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using mint = modint1000000007;

int main(){

    int n, k;
    cin >> n >> k;
    vector<int> a(n), p(k);
    rep(i,n) cin >> a[i];
    rep(i,k) cin >> p[i];

    vector<vector<mint>> dp(n + 1, vector<mint>(k + 1));
    rep(i,n + 1) dp[i][0] = 1;

    rep(i,n){
        rep(j,k){
            if(a[i] == p[j]) dp[i + 1][j + 1] = dp[i][j + 1] + dp[i][j];
            else dp[i + 1][j + 1] = dp[i][j + 1];
        }
    }

    cout << dp[n][k].val() << endl;
     
    return 0;
}