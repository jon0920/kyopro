#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){
    
    int n, k, d;
    cin >> n >> k >> d;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, -INF));
    dp[0][0] = 0;
    rep(i,n){
        rep(j,k){
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            dp[min(n, i + 1 + d)][j + 1] = max(dp[min(n, i + 1 + d)][j + 1], dp[i][j] + a[i]);
        }
    }

    ll res = 0;
    rep(i,n + 1) res = max(res, *max_element(dp[i].begin(), dp[i].end()));
    cout << res << endl;
    
    return 0;
}