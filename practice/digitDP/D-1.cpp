#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

ll dp[15][2][15];

int main(){
    
    string N;
    cin >> N;
    int n = N.size();

    dp[0][0][0] = 1;
    rep(i,n){
        rep(smaller,2){
            rep(cnt,12){
                if(dp[i][smaller][cnt] == 0) continue;
                
                int lim = smaller ? 9 : (N[i] - '0');
                rep(d,lim + 1){
                    int nxt_smaller = smaller || (d < lim);
                    int nxt_cnt = cnt + (d == 1);
                    dp[i + 1][nxt_smaller][nxt_cnt] += dp[i][smaller][cnt];
                }
            }
        }
    }

    ll ans = 0;
    rep(smaller,2){
        rep(cnt,12){
            ans += dp[n][smaller][cnt] * cnt;
        }
    }

    cout << ans << endl;
    
    return 0;
}