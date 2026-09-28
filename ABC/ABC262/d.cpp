#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using mint = modint998244353;

int main(){
    
    int n;
    cin >> n;
    vector<ll> A(n);
    rep(i,n) cin >> A[i];

    mint ans = 0;
    for(int i = 1; i <= n; i++){
        //Aの中からi個選んだ時のあまり
        vector<vector<mint>> dp(i + 1, vector<mint>(i, 0));
        dp[0][0] = 1;

        for(ll a : A){
            int x = a % i;

            for(int j = i - 1; j >= 0; j--){
                for(int r = 0; r < i; r++){
                    int nr = (r + x) % i;
                    dp[j + 1][nr] += dp[j][r];
                }
            }
        }
        ans += dp[i][0];
    }

    cout << ans.val() << endl;
    
    return 0;
}