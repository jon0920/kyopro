#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int t;
    cin >> t;
    rep(ti,t){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<ll> x(n), y(n - 1);
        rep(i,n) cin >> x[i];
        rep(i,n - 1) cin >> y[i];
        vector<vector<ll>> dp(n, vector<ll>(2, -1e18));
        if(s[0] == 'S'){
            dp[0][0] = 0; dp[0][1] = -x[0];
        } else {
            dp[0][0] = -x[0]; dp[0][1] = 0;
        }
        for(int i = 1; i < n; i++){
            if(s[i] == 'S'){
                dp[i][0] = max(dp[i][0], max(dp[i - 1][0], dp[i - 1][1] + y[i - 1]));
                dp[i][1] = max(dp[i][1], max(dp[i - 1][0] - x[i], dp[i - 1][1] - x[i]));
            } else {
                dp[i][0] = max(dp[i][0], max(dp[i - 1][0] - x[i], dp[i - 1][1] - x[i] + y[i - 1]));
                dp[i][1] = max(dp[i][1], max(dp[i - 1][0], dp[i - 1][1]));
            }
        }
        cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
    }

    
    return 0;
}