#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 4e18;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int main(){

    int n, m;
    cin >> n >> m;
    vector<ll> r(n), t(n);
    rep(i,n) cin >> r[i] >> t[i];

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -INF));
    dp[0][0] = 0;

    rep(i,n){
        rep(j,m+1){
            if(dp[i][j] == INF) continue;
            chmax(dp[i + 1][j], dp[i][j]);
            if(j + t[i] <= m){
                chmax(dp[i + 1][j + t[i]], dp[i][j] + r[i]);
            }
        }
    }

    ll ans = -INF;
    for(auto x : dp[n]) ans = max(ans, x);
    cout << ans << endl;

    return 0;
}