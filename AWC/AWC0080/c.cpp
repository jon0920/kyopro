#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<int> t(n);
    vector<ll> a(n);
    rep(i,n) cin >> t[i] >> a[i];

    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, -1e18));
    dp[0][0] = 0;
    rep(i,n){
        if(t[i] == 1){
            rep(j,k + 1){
                chmax(dp[i + 1][j], dp[i][j]);
                if(j != k) chmax(dp[i + 1][j + 1], dp[i][j] + a[i]);
            }
        } else {
            rep(j, k + 1){
                chmax(dp[i + 1][j], dp[i][j]);
                chmax(dp[i + 1][max(0, j - 1)], dp[i][j] + a[i]);
            }
        }
    }

    cout << dp[n][0] << endl;
    
    return 0;
}