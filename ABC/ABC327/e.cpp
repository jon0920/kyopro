#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const double INF = 10000000.0;

int main(){
    
    int n;
    cin >> n;
    vector<double> p(n);
    rep(i,n) cin >> p[i];

    vector<vector<double>> dp(n + 1,vector<double>(n + 1, -INF));
    dp[0][0] = 0.0;

    rep(i,n){
        rep(j,n + 1){
            if(dp[i][j] != -INF){
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                if(j != n) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] * 0.9 + p[i]);
            }
        }
    }

    double ans = -INF;
    double denomi = 1.0;
    int num = 0;
    for(int i = 1; i <= n; i++){
        double cur = (dp[n][i] / denomi) - 1200 / sqrt(i);
        ans = max(ans, cur);
        denomi *= 0.9;
        denomi += 1.0;
    }

    cout << fixed << setprecision(17);
    cout << ans << endl;
    
    return 0;
}