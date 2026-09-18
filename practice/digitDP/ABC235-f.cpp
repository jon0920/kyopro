#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); i++)
using mint = modint998244353;

int main(){
    
    string N;
    int m;
    cin >> N >> m;
    vector<int> c(m);
    rep(i,m) cin >> c[i];
    int n = N.size();

    mint dp_cnt[2][2][1<<10];
    mint dp_sum[2][2][1<<10];
    memset(dp_cnt, 0, sizeof(dp_cnt));
    memset(dp_sum, 0, sizeof(dp_sum));
    dp_cnt[0][0][0] = 1;
    dp_sum[0][0][0] = 0;

    rep(i,n){
        mint next_dp_cnt[2][2][1<<10];
        mint next_dp_sum[2][2][1<<10];
        rep(smaller,2){
            rep(started,2){
                rep(mask,1<<10){
                    int lim = smaller ? 9 : N[i] - '0';
                    rep(d,lim + 1){
                        int next_smaller = smaller | (d < lim);
                        int next_started = started | (d != 0);
                        int next_mask = mask;
                        if(next_started) next_mask |= (1 << d);

                        mint cnt = dp_cnt[smaller][started][mask];
                        
                        next_dp_cnt[next_smaller][next_started][next_mask] += cnt;
                        next_dp_sum[next_smaller][next_started][next_mask] += dp_sum[smaller][started][mask] * 10 + d * cnt;
                    }
                }
            }
        }
        swap(dp_cnt, next_dp_cnt);
        swap(dp_sum, next_dp_sum);
    }

    int target = 0;
    rep(i,m){
        target |= (1 << c[i]);
    }

    mint ans = 0;
    rep(smaller,2){
        rep(mask,1<<10){
            if((mask & target) == target){
                ans += dp_sum[smaller][1][mask];
            }
        }
    }

    cout << ans.val() << endl;
    
    return 0;
}