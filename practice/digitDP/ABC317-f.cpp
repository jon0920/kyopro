#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using mint = modint998244353;

const int B[4][3] = {{0,0,0}, {0,1,1}, {1,0,1}, {1,1,0}};

int main(){
    
    ll n;
    cin >> n;
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;

    static mint dp[62][2][2][2][11][11][11];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0][0][0][0] = 1;

    rep(i,61){
        int d = (n >> (60 - i) & 1);
        rep(smaller1,2){
            rep(smaller2,2){
                rep(smaller3,2){
                    rep(rem1,a1){
                        rep(rem2,a2){
                            rep(rem3,a3){
                                if(dp[i][smaller1][smaller2][smaller3][rem1][rem2][rem3] == 0) continue;

                                for(auto [b1, b2, b3] : B){
                                    int next_rem1 = (rem1 * 2 + b1) % a1;
                                    int next_rem2 = (rem2 * 2 + b2) % a2;
                                    int next_rem3 = (rem3 * 2 + b3) % a3;
                                 
                                    if(smaller1 == 0 && d < b1) continue;
                                    if(smaller2 == 0 && d < b2) continue;
                                    if(smaller3 == 0 && d < b3) continue;

                                    int next_smaller1 = smaller1 | (d > b1);
                                    int next_smaller2 = smaller2 | (d > b2);
                                    int next_smaller3 = smaller3 | (d > b3);

                                    dp[i + 1][next_smaller1][next_smaller2][next_smaller3][next_rem1][next_rem2][next_rem3]
                                    += dp[i][smaller1][smaller2][smaller3][rem1][rem2][rem3];
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    ll x1 = (n / lcm(a2, a3)) + 1;
    ll x2 = (n / lcm(a1, a3)) + 1;
    ll x3 = (n / lcm(a1, a2)) + 1;

    mint ans = 0;
    rep(smaller1,2){
        rep(smaller2,2){
            rep(smaller3,2){
                ans += dp[61][smaller1][smaller2][smaller3][0][0][0];
            }
        }
    }
    ans -= (x1 + x2 + x3) - 2;

    cout << ans.val() << endl;
    
    return 0;
}