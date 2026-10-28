#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){
    
    ll n, c;
    cin >> n >> c;

    vector<vector<ll>> dp(n + 1, vector<ll>(2, -INF));
    dp[0][0] = 0;

    rep(i,n){
        ll a;
        cin >> a;
        dp[i + 1][0] = max(dp[i][0], dp[i][1]);
        dp[i + 1][1] = max(dp[i][0] + a, dp[i][1] + a + c);
    }

    cout << max(dp[n][0], dp[n][1]) << endl;
    
    return 0;
}