#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 4e18;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int main(){

    int n;
    cin >> n;
    vector<vector<ll>> dp(n + 1, vector<ll>(2, -INF));
    dp[0][0] = dp[0][1] = 0;

    rep(i,n){
        ll a;
        cin >> a;
        chmax(dp[i + 1][0], dp[i][1]);
        chmax(dp[i + 1][0], dp[i][0]);
        chmax(dp[i + 1][1], dp[i][0] + a);
    }

    cout << max(dp[n][0], dp[n][1]) << endl;

    return 0;
}