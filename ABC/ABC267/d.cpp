#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int main(){
    
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -INF));
    dp[0][0] = 0;
    rep(i,n){
        for(ll j = 0; j <= m; j++){
            chmax(dp[i + 1][j], dp[i][j]);
            if(j != m){
                chmax(dp[i + 1][j + 1], dp[i][j] + a[i] * (j + 1));
            }
        }
    }

    cout << dp[n][m] << endl;
    
    return 0;
}