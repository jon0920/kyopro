#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int main(){
    
    int n;
    cin >> n;
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
    rep(i,n){
        int x; ll y;
        cin >> x >> y;
        chmax(dp[i + 1][0], dp[i][0]);
        chmax(dp[i + 1][1], dp[i][1]);
        if(x == 0){
            chmax(dp[i + 1][0], max(dp[i][0], dp[i][1]) + y);
        } else {
            chmax(dp[i + 1][1], dp[i][0] + y);
        }
    }

    cout << max(dp[n][0], dp[n][1]) << endl;
    
    return 0;
}