#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){

    int n, d;
    cin >> n >> d;
    vector<vector<ll>> dp(n + 1, vector<ll>(d + 1, INF));
    rep(i,n + 1) dp[i][0] = 0;

    rep(i,n){
        int c, f;
        cin >> c >> f;
        for(int j = 0; j <= d; j++){
            chmin(dp[i + 1][j], dp[i][j]);

            if(dp[i + 1][max(0, j - f)] != INF){
                chmin(dp[i + 1][j], dp[i + 1][max(0, j - f)] + c);
            }
        }
    }

    cout << dp[n][d] << endl;

    return 0;
}