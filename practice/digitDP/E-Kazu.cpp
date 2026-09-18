#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using mint = modint1000000007;

mint dp[10010][2][110];

int main(){
    
    int d;
    string s;
    cin >> d >> s;
    int n = s.size();

    dp[0][0][0] = 1;

    rep(i,n){
        rep(j,d){
            rep(k,10){
                dp[i + 1][1][(j + k) % d] += dp[i][1][j];
            }
            int lim = s[i] - '0';
            rep(k,lim){
                dp[i + 1][1][(j + k) % d] += dp[i][0][j];
            }
            dp[i + 1][0][(j + lim) % d] += dp[i][0][j];
        }
    }

    cout << (dp[n][0][0] + dp[n][1][0] - 1).val() << endl;
    
    return 0;
}