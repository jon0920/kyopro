#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using mint = modint;

int MAX = 5010;

int main(){
    
    int t, m;
    cin >> t >> m;
    mint::set_mod(m);

    vector<vector<mint>> dp(MAX, vector<mint>(MAX, 0));
    dp[0][0] = 1;
    for(int i = 1; i < MAX; i++){
        dp[i][0] = 1;
        for(int j = 1; j <= i; j++){
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    while(t--){
        int n;
        cin >> n;
        int s = 0;
        mint res = 1;
        rep(i,n){
            int c;
            cin >> c;
            s += c;
            res *= dp[s][c];
        }

        cout << res.val() << endl;
    }
    
    return 0;
}