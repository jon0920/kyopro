#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll l, r;
    cin >> l >> r;
    l--;

    auto solve = [](ll x) -> ll {
        string s = to_string(x);
        int n = s.size();
        if(x < 10) return 1;
        ll dp[20][2][10] = {};
        dp[0][0][0] = 1;
        rep(i,n){
            rep(smaller,2){
                rep(first,10){
                    if(dp[i][smaller][first] == 0) continue;

                    int lim = smaller ? 9 : s[i] - '0';
                    rep(d,lim + 1){
                        int next_smaller = smaller | (d < lim);
                        if(first == 0){
                            int next_first = d;
                            dp[i + 1][next_smaller][next_first] += dp[i][smaller][first];
                        } else {
                            if(d >= first) continue;
                            dp[i + 1][next_smaller][first] += dp[i][smaller][first];
                        }
                    }
                }
            }
        }

        ll res = 0;
        rep(smaller,2){
            for(int first = 1; first <= 9; first++) res += dp[n][smaller][first];
        }
        return res;
    };

    cout << solve(r) - solve(l) << endl;
    
    return 0;
}