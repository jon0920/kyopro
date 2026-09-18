#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, l, k;
    cin >> n >> l >> k;
    vector<vector<int>> dp(n + 1, vector<int>(l + 1, -1e9));
    dp[0][0] = 0;
    rep(s,n){
        int w, b;
        cin >> w >> b;
        for(int i = s; i >= 0; i--){
            for(int j = w; j <= l; j++){
                if(dp[i][j - w] != -1e9){
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - w] + b);
                }
            }
        }
    }

    int ans = -1;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= l; j++){
            if(dp[i][j] != -1e9){
                int space = ((l - j) + i) /(i + 1);
                if(space < k){
                    ans = max(ans, dp[i][j]);
                }
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}