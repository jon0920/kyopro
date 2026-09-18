#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    ll n, K;
    cin >> n >> K;
    vector<vector<ll>> ab(2, vector<ll>(n));
    rep(i,2) rep(j,n) cin >> ab[i][j]; 

    vector<vector<bool>> dp(n, vector<bool>(2, false));
    dp[0][0] = true; dp[0][1] = true;

    for(int i = 1; i < n; i++){
        rep(j,2){
            rep(k,2){
                if(abs(ab[j][i - 1] - ab[k][i]) <= K && dp[i-1][j]){
                    dp[i][k] = true;
                }
            }
        }
    }

    if(dp[n-1][0] || dp[n-1][1]) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}