#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using mint = modint1000000007;

int main(){
    
    string k;
    int d;
    cin >> k >> d;
    int n = k.size();

    static mint dp[10010][2][110];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;

    rep(i,n){
        rep(smaller,2){
            rep(rem,d){
                if(dp[i][smaller][rem] == 0) continue;

                int lim = smaller ? 9 : k[i] - '0';
                rep(dig,lim + 1){
                    int next_smaller = smaller | (dig < lim);
                    int next_rem = (rem + dig) % d;
                    dp[i + 1][next_smaller][next_rem] += dp[i][smaller][rem];
                }
            }
        }
    }

    mint ans = dp[n][0][0] + dp[n][1][0] - 1;
    cout << ans.val() << endl;

    return 0;
}