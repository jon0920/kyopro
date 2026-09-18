#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using mint = modint998244353;

int main(){
    
    string s;
    cin >> s;
    int n = s.size();

    vector<vector<mint>> dp(n + 1, vector<mint>(n + 1));
    dp[0][0] = 1;

    rep(i,n){
        rep(j,n){
            if(s[i] == ')' || s[i] == '?'){
                if(j - 1 >= 0){
                    dp[i + 1][j - 1] += dp[i][j];
                }
            }
            if(s[i] == '(' || s[i] == '?'){
                if(j + 1 <= n){
                    dp[i + 1][j + 1] += dp[i][j];
                }
            }
        }
    }

    cout << dp[n][0].val() << endl;
    
    return 0;
}