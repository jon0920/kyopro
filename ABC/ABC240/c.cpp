#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;


int main() {
    
    int n, x;
    cin >> n >> x;
    vector<vector<bool>> dp(n + 1, vector<bool>(x + 1, false));
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];

    dp[0][0] = true;
    rep(i,n){
        rep(j,x+1){
            if(dp[i][j]){
                if(j + a[i] <= x) dp[i + 1][j + a[i]] = true;
                if(j + b[i] <= x) dp[i + 1][j + b[i]] = true;
            }
        }
    }

    cout << (dp[n][x] ? "Yes" : "No") << endl;
    
    return 0;
}