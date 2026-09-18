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
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    vector<vector<vector<mint>>> dp(n, vector<vector<mint>>(n, vector<mint>(n + 1)));
    for(int i = n; i >= 0; i--){
        for(int j = i + 1; j < n; j++){
            dp[i][j][2]++;
            for(int l = 2; l < n - i; l++){
                for(int k = j + 1; k < n; k++){
                    if(a[k] - a[j] != a[j] - a[i]) continue;
                    dp[i][j][l + 1] = (dp[i][j][l + 1] + dp[j][k][l]);
                }
            }
        }
    }
    vector<mint> ans(n + 1);
    ans[1] = n;
    rep(i,n){
        rep(j,n){
            for(int l = 2; l < n - i + 1; l++){
                ans[l] = ans[l] + dp[i][j][l];
            }
        }
    }

    for(int i = 1; i <= n; i++) cout << ans[i].val() << " ";
    cout << endl;
    
    return 0;
}