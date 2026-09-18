#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int main() {
    
    int n;
    cin >> n;
    const ll INF = 1e18;
    vector<vector<ll>> dp(n + 1, vector<ll>(2, -INF));
    dp[0][0] = 0;
    rep(i,n){
        int x; ll y;
        cin >> x >> y;
        if(x == 1){
            chmax(dp[i + 1][0], dp[i][0]);
            chmax(dp[i + 1][1], dp[i][1]);
            chmax(dp[i + 1][1], dp[i][0] + y);
        }
        else{
            chmax(dp[i + 1][0], dp[i][0]);
            chmax(dp[i + 1][0], dp[i][0] + y);
            chmax(dp[i + 1][0], dp[i][1] + y);
            chmax(dp[i + 1][1], dp[i][1]);
        }
    }

    ll ans = max(dp[n][0], dp[n][1]);
    cout << ans << endl;
    
    return 0;
}