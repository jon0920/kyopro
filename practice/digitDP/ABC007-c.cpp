#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll a, b;
    cin >> a >> b;
    a--;
    string A = to_string(a);
    string B = to_string(b);

    auto solve = [](string s){
        int n = s.size();
        ll dp[20][2][2] = {};
        dp[0][0][0] = 1;
        rep(i,n){ 
            rep(smaller,2){
                rep(has_49,2){
                    int lim = smaller ? 9 : s[i] - '0';
                    rep(d,lim + 1){
                        int next_smaller = smaller || (d < lim);
                        int next_has_49 = has_49 || d == 4 || d == 9;
                        dp[i + 1][next_smaller][next_has_49] += dp[i][smaller][has_49];
                    }
                }
            }
        }
        return dp[n][0][1] + dp[n][1][1];
    };

    cout << solve(B) - solve(A) << endl;
    
    return 0;
}