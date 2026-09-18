#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using mint = modint998244353;

int main(){
    
    string N;
    cin >> N;
    int n = N.size();

    //dp[digit][smaller][is_started][rem_3][mask]
    static mint dp[510][2][2][3][1<<10];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0][0] = 1;

    rep(i,n){
        rep(smaller,2){
            rep(started,2){
                rep(rem3,3){
                    rep(mask,1<<10){
                        if(dp[i][smaller][started][rem3][mask] == 0) continue;

                        int lim = smaller ? 9 : N[i] - '0';
                        rep(d,lim + 1){
                            int next_smaller = smaller | (d < lim);
                            int next_started = started | (d > 0);
                            int next_rem3 = rem3;
                            int next_mask = mask;
                            if(next_started){
                                next_rem3 = (rem3 + d) % 3;
                                next_mask |= (1 << d);
                            }
                            dp[i + 1][next_smaller][next_started][next_rem3][next_mask] += dp[i][smaller][started][rem3][mask];
                        }
                    }
                }
            }
        }
    }

    mint ans = 0;
    rep(smaller,2){
        rep(rem3,3){
            rep(mask,1<<10){
                int cond1 = (rem3 == 0);
                int cond2 = ((mask >> 3) & 1);
                int cond3 = (__builtin_popcount(mask) == 3);

                if((cond1 + cond2 + cond3) == 1){
                    ans += dp[n][smaller][1][rem3][mask];
                }
            }
        }
    }

    cout << ans.val() << endl;
    
    return 0;
}