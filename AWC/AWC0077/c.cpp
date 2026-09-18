#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int INF = 1e9;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    vector<vector<int>> dp(n + 1, vector<int>(s + 1, INF));
    dp[0][0] = 0;
    rep(i,n){
        rep(j,s + 1){
            chmin(dp[i + 1][j], dp[i][j]);
            if(j + a[i] <= s){
                chmin(dp[i + 1][j + a[i]], dp[i][j] + 1);
            }
        }
    }

    if(dp[n][s] == INF) cout << -1 << endl;
    else cout << dp[n][s] << endl;
    
    return 0;
}