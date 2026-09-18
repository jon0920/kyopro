#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int main(){

    int n;
    cin >> n;
    vector<vector<ll>> abc(3, vector<ll>(n));
    rep(i,3) rep(j,n) cin >> abc[i][j];

    vector<vector<ll>> dp(3, vector<ll>(n, -INF));
    dp[0][0] = abc[0][0];
    rep(i,n - 1){
        rep(j,3){
            chmax(dp[j][i + 1], dp[j][i] + abc[j][i + 1]);
            if(j != 2) chmax(dp[j + 1][i + 1], dp[j][i] + abc[j + 1][i + 1]);
        }
    }    

    cout << dp[2][n - 1] << endl;

    return 0;
}