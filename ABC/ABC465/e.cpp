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
    
    //dp[i桁目まで][nより小さいか][先頭0][桁和%3][数字が使われているか]
    static mint dp[510][2][2][3][1<<10];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0][0] = 1;
    
    rep(i,n){
        rep(smaller,2){
            rep(started,2){
                rep(rem,3){
                    for(int dig = 0; dig < (1 << 10); dig++){
                        if(dp[i][smaller][started][rem][dig] == 0) continue;

                        int lim = (smaller ? 9 : s[i] - '0');
                        rep(d,lim + 1){
                            int next_smaller = smaller | (d < lim);
                            int next_started = started | (d != 0);
                            int next_rem = (rem + d) % 3;
                            int next_dig = dig;
                            if(next_started){
                                next_dig |= (1 << d);
                            }
                            dp[i + 1][next_smaller][next_started][next_rem][next_dig] += dp[i][smaller][started][rem][dig];
                        }
                    }
                }
            }
        }
    }

    mint ans = 0;
    rep(smaller,2){
        rep(rem,3){
            for(int dig = 0; dig < (1 << 10); dig++){
                int cnt = 0;
                if(rem == 0) cnt++;
                if(dig & (1 << 3)) cnt++;
                if(__builtin_popcount(dig) == 3) cnt++;
                
                if(cnt == 1){
                    ans += dp[n][smaller][1][rem][dig];
                }
            }
        }
    }

    cout << ans.val() << endl;

    return 0;
}