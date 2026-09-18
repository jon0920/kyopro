#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using mint = modint998244353;

int main(){
    
    int t;
    cin >> t;
    rep(ti,t){
        ll n, k;
        cin >> n >> k;

        static mint dp_cnt[61][2][65];
        static mint dp_sum[61][2][65];
        memset(dp_cnt, 0, sizeof(dp_cnt));
        memset(dp_sum, 0, sizeof(dp_sum));
        dp_cnt[0][0][0] = 1;
        dp_sum[0][0][0] = 0;

        rep(i,60){
            int d = 59 - i;
            int cur_dig = (n >> d) & 1;

            rep(smaller,2){
                rep(cnt,k + 1){
                    if(dp_cnt[i][smaller][cnt].val() == 0) continue;

                    rep(b,2){
                        if(smaller == 0 && cur_dig < b) continue;

                        int next_smaller = smaller | (cur_dig > b);
                        int next_cnt = cnt + b;
                        if(next_cnt > k) continue;

                        dp_cnt[i + 1][next_smaller][next_cnt] += dp_cnt[i][smaller][cnt];
                        dp_sum[i + 1][next_smaller][next_cnt] += dp_sum[i][smaller][cnt];

                        if(b == 1){
                            mint val = (1LL << d);
                            dp_sum[i + 1][next_smaller][next_cnt] += dp_cnt[i][smaller][cnt] * val;
                        }
                    }
                }
            }
        }

        mint ans = dp_sum[60][0][k] + dp_sum[60][1][k];
        cout << ans.val() << endl;
    }
    
    return 0;
}