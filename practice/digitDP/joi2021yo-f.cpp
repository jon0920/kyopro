#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using mint = modint;

int main(){
    
    string A, B;
    int m;
    cin >> A >> B >> m;

    mint::set_mod(10000);

    auto solve = [&](string S){
        int n = S.size();
        static mint dp[510][2][4][10][505];
        //dp[digit][smaller][state][last_d][rem_m]
        //state 0:!started 1:first digit 2:next dec 3:next inc
        memset(dp, 0, sizeof(dp));
        dp[0][0][0][0][0] = 1;

        rep(i,n){
            rep(smaller,2){
                rep(state,4){
                    rep(last_d,10){
                        rep(rem,m){
                            if(dp[i][smaller][state][last_d][rem] == 0) continue;

                            int lim = smaller ? 9 : S[i] - '0';
                            rep(d,lim + 1){
                                int next_smaller = smaller | (d < lim);
                                int next_state = -1;
                                int next_last_d = d;
                                int next_rem = (rem * 10 + d) % m;

                                if(state == 0){
                                    if(d == 0) next_state = 0;
                                    else next_state = 1;
                                } else if(state == 1){
                                    if(d > last_d) next_state = 2;
                                    else if(d < last_d) next_state = 3;
                                } else if(state == 2){
                                    if(d < last_d) next_state = 3;
                                } else {
                                    if(d > last_d) next_state = 2;
                                }
                                if(next_state == -1) continue;

                                dp[i + 1][next_smaller][next_state][next_last_d][next_rem] += dp[i][smaller][state][last_d][rem];
                            }
                        }
                    }
                }
            }
        }

        mint res = 0;
        rep(smaller,2){
            for(int state = 1; state < 4; state++){
                rep(last_d,10){
                    res += dp[n][smaller][state][last_d][0];
                }
            }
        }
        
        return res;
    };

    auto is_ok = [&](string S){
        int n = S.size();
        
        int rem = 0;
        for(char c : S) rem = (rem * 10 + (c - '0')) % m;
        if(rem != 0) return 0;
        
        if(n == 1) return 1;

        int state = 1;
        for(int i = 1; i < n; i++){
            int prev = S[i - 1] - '0';
            int cur = S[i] - '0';
            if(state == 1){
                if(cur > prev) state = 2;
                else if(cur < prev) state = 3;
                else return 0;
            } else if(state == 2){
                if(cur < prev) state = 3;
                else return 0;
            } else if(state == 3){
                if(cur > prev) state = 2;
                else return 0;
            }
        }
        return 1;
    };

    mint ans = solve(B) - solve(A) + is_ok(A);
    cout << ans.val() << endl;
    
    return 0;
}