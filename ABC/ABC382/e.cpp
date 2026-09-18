#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, x;
    cin >> n >> x;
    vector<int> p(n);
    rep(i,n) cin >> p[i];

    vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0.0));
    dp[0][0] = 1.0;

    for(int i = 1; i <= n; i++){
        double P = p[i - 1] / 100.0;
        for(int j = 0; j <= i; j++){
            dp[i][j] += dp[i - 1][j] * (1.0 - P);
            if(j > 0){
                dp[i][j] += dp[i - 1][j - 1] * P;
            }
        }
    }

    vector<double> prob(n + 1);
    rep(i,n + 1) prob[i] = dp[n][i];

    vector<double> E(x + 1, 0.0);
    E[0] = 0.0;

    for(int i = 1; i <= x; i++){
        double sum_E = 1.0;
        for(int j = 1; j <= n; j++){
            int nxt = max(0, i - j);
            sum_E += prob[j] * E[nxt];
        }
        E[i] = sum_E / (1.0 - prob[0]);
    }

    cout << fixed << setprecision(17);
    cout << E[x] << endl;

    return 0;
}