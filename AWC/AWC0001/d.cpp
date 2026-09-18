#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

int main(){

    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -INF));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        dp[i][b[i - 1]] = a[i - 1];
    }
    
    rep(i,n){
        for(int j = 1; j <= k; j++){
            if(i + j > n) break;
            rep(cost,m){
                if(cost + b[i + j - 1] <= m){
                    chmax(dp[i + j][cost + b[i + j - 1]], dp[i][cost] + a[i + j - 1]);
                }
            }
        }
    }

    ll ans = -INF;
    rep(i,n + 1) rep(j, m + 1) ans = max(ans, dp[i][j]);
    cout << ans << endl;

    return 0;
}