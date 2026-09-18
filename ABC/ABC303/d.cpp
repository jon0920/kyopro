#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){
    
    ll x, y, z;
    string s;
    cin >> x >> y >> z >> s;
    int n = s.size();
    
    vector<vector<ll>> dp(n + 1, vector<ll>(2, INF));
    dp[0][0] = 0;

    rep(i,n){
        int upper;
        if(s[i] == 'a') upper = 0;
        else upper = 1;

        rep(j,2){
            rep(k,2){
                ll nxt = dp[i][j];
                if(j != k) nxt += z;

                if(upper == k) nxt += x;
                else nxt += y;

                dp[i + 1][k] = min(dp[i + 1][k], nxt);
            }
        }
    }

    cout << min(dp[n][0], dp[n][1]) << endl;
    
    return 0;
}