#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> c(n, vector<ll>(m));
    rep(i,n) rep(j,m) cin >> c[i][j];

    vector<ll> dp(m);
    rep(i,n){
        vector<ll> ndp(m);
        ll mn = 1e18;
        rep(j,m){
            mn = min(mn, dp[j]);
            ndp[j] = mn + c[i][j];
        }
        dp = move(ndp);
    }

    cout << *min_element(dp.begin(), dp.end()) << endl;
    
    return 0;
}