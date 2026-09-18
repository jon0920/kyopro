#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll N;
    cin >> N;
    string n = to_string(N);
    int m = n.size();

    ll ans = 0;
    for(int S = 1; S <= 126; S++){

        ll dp[20][2][130][130];
        memset(dp, 0, sizeof(dp));
        dp[0][0][0][0] = 1;

        rep(i,m){
            int cur_d = n[i] - '0';
            rep(smaller,2){
                rep(sum,130){
                    rep(rem,S){
                        if(dp[i][smaller][sum][rem] == 0) continue;

                        int lim = (smaller ? 9 : cur_d);
                        rep(d,lim + 1){
                            int next_smaller = smaller || (d < lim);
                            int next_sum = sum + d;
                            if(next_sum > S) continue;
                            int next_rem = (rem * 10 + d) % S;
                            dp[i + 1][next_smaller][next_sum][next_rem] += dp[i][smaller][sum][rem];
                        }
                    }
                }
            }
        }
        ans += dp[m][0][S][0] + dp[m][1][S][0];
    }

    cout << ans << endl;
    
    return 0;
}