#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); i++)

using mint = modint998244353;

int main(){
    
    int t;
    cin >> t;
    while(t--){
        ll n; int K;
        cin >> n >> K;
        mint dp_cnt[61][2][61]{};
        mint dp_sum[61][2][61]{};
        dp_cnt[0][0][0] = 1;

        for(int d = 0; d < 60; d++){
            int bit = (n >> (59 - d)) & 1;
            rep(smaller,2){
                int lim = smaller ? 1 : bit;
                rep(k,K + 1){
                    rep(j,lim + 1){
                        if(j + k > K) continue;
                        int next_smaller = smaller | (j < lim);

                        dp_cnt[d + 1][next_smaller][j + k] += dp_cnt[d][smaller][k];
                        dp_sum[d + 1][next_smaller][j + k] += dp_sum[d][smaller][k] * 2 + dp_cnt[d][smaller][k] * j;
                    }
                }
            }
        }

        mint ans = dp_sum[60][0][K] + dp_sum[60][1][K];
        cout << ans.val() << endl;
    }
    
    return 0;
}