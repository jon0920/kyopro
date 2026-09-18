#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using mint = modint1000000007;

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<bool> ok(n + 1, true);
    rep(i,m){
        int b;
        cin >> b;
        ok[b] = false;
    }

    vector<mint> dp(n + 1);
    dp[0] = 1;
    rep(i,n){
        for(int j = 1; j <= 3; j++){
            if(i + j <= n && ok[i + j]){
                dp[i + j] += dp[i];
            }
        }
    }
    cout << dp[n].val() << endl;
    
    return 0;
}