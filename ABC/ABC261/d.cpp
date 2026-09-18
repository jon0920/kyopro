#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int main(){

    int n, m;
    cin >> n >> m;
    vector<ll> x(n);
    rep(i,n) cin >> x[i];
    vector<ll> pts(5010);
    rep(i,m){
        ll c, y;
        cin >> c >> y;
        pts[c] = y;
    }

    const ll INF = 1e18;
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -INF));
    dp[0][0] = 0;
    rep(i,n){
        rep(j,n + 1){
            chmax(dp[i + 1][0], dp[i][j]);
            if(j != n){
                chmax(dp[i + 1][j + 1], dp[i][j] + x[i] + pts[j + 1]);
            }
        }
    }

    ll ans = 0;
    for(auto x : dp[n]) ans = max(ans, x);
    cout << ans << endl;

    return 0;
}