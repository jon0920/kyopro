#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

const int INF = 1e9;

int main(){

    int n, s;
    cin >> n >> s;
    vector<pair<int,int>> vc(n);
    rep(i,n) cin >> vc[i].first >> vc[i].second;

    vector<vector<int>> dp(n + 1, vector<int>(s + 1, -1));
    dp[0][0] = 0;

    rep(i,n){
        auto [v, c] = vc[i];
        rep(j,s + 1){
            if(dp[i][j] == -1) continue;
            chmax(dp[i + 1][j], dp[i][j]);
            if(j + c <= s){
                chmax(dp[i + 1][j + c], dp[i][j] + v);
            }
        }
    }

    int ans = -1;
    rep(i,n + 1){
        ans = max(ans, dp[i][s]);
    }

    cout << ans << endl;

    return 0;
}