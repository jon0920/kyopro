#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){
    
    int n, k;
    cin >> n >> k;

    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(k + 1, vector<ll>(2, -INF)));
    dp[0][0][0] = 0;

    rep(i,n){
        ll a;
        cin >> a;
        rep(j,k + 1){
            dp[i + 1][j][0] = max({dp[i + 1][j][0], dp[i][j][0], dp[i][j][1]});
            if(j + 1 <= k) dp[i + 1][j + 1][1] = max(dp[i + 1][j + 1][1], dp[i][j][0] + a); 
        }
    }

    cout << max(dp[n][k][0], dp[n][k][1]) << endl;
    
    return 0;
}