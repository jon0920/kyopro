#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

const ll MOD = 998244353;

int main() {
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    vector<vector<ll>> dp(n, vector<ll>(10));
    dp[0][a[0]] = 1;

    rep(i,n-1){
        rep(j,10){
            int sum = (j + a[i + 1]) % 10;
            int prod = (j * a[i + 1]) % 10;
            dp[i + 1][sum] += dp[i][j];
            dp[i + 1][prod] += dp[i][j];
            dp[i + 1][sum] %= MOD;
            dp[i + 1][prod] %= MOD;
        }
    }

    rep(i,10){
        cout << dp[n-1][i] << endl;
    }
    
    return 0;
}