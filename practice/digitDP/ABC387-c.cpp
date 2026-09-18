#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll l, r;
    cin >> l >> r;
    l--;
    string L = to_string(l);
    string R = to_string(r);

    auto solve = [](string s) -> ll {
        int n = s.size();

        ll dp[20][2][10] = {};
        dp[0][0][0] = 1;
        rep(i,n){
            rep(smaller,2){
                rep(first_dig,10){
                    if(dp[i][smaller][first_dig] == 0) continue;

                    int lim = smaller ? 9 : s[i] - '0';
                    rep(d,lim + 1){
                        int next_smaller = smaller || (d < lim);
                        if(first_dig == 0){
                            int next_first = d;
                            dp[i + 1][next_smaller][next_first] += dp[i][smaller][first_dig];
                        } else {
                            if(d >= first_dig) continue;
                            dp[i + 1][next_smaller][first_dig] += dp[i][smaller][first_dig];
                        }
                    }
                }
            }
        }
        
        ll res = 0;
        rep(smaller,2){
            for(int first_dig = 1; first_dig <= 9; first_dig++){
                res += dp[n][smaller][first_dig];
            }
        }
        return res;
    };

    cout << solve(R) - solve(L) << endl;
    
    return 0;
}