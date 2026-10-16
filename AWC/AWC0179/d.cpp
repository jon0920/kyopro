#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using mint = modint998244353;

int main(){
    
    int n;
    string s;
    cin >> n >> s;

    vector<vector<mint>> dp(n, vector<mint>(2));
    if(s[0] == 'A') dp[0][0] = 1;
    else if(s[0] == 'B') dp[0][1] = 1;
    else dp[0][0] = 1, dp[0][1] = 1;

    for(int i = 1; i < n; i++){
        if(s[i] == 'A'){
            dp[i][0] = dp[i - 1][1];
        } else if(s[i] == 'B'){
            dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
        } else {
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
        }
    }

    mint ans = dp[n - 1][0] + dp[n - 1][1];
    cout << ans.val() << endl;
    
    return 0;
}