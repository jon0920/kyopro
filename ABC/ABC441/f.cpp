#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<ll> p(n), v(n);
    rep(i,n) cin >> p[i] >> v[i];
    
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
    rep(i,n){
        rep(j,m + 1){
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if(j + p[i] <= m) dp[i + 1][j + p[i]] = max(dp[i + 1][j + p[i]], dp[i][j] + v[i]);
        }
    }

    string res = "";
    vector<bool> can_reach(m + 1);
    can_reach[m] = true;
    for(int i = n; i > 0; i--){
        bool skip = false, take = false;
        vector<bool> nxt_can_reach(m + 1);
        rep(j,m + 1){
            if(!can_reach[j]) continue;
            if(dp[i][j] == dp[i - 1][j]){
                skip = true;
                nxt_can_reach[j] = true;
            }
            if(j - p[i - 1] >= 0 && dp[i][j] == dp[i - 1][j - p[i - 1]] + v[i - 1]){
                take = true;
                nxt_can_reach[j - p[i - 1]] = true;
            }
        }

        if(skip && take) res += "B";
        else if(skip) res += "C";
        else if(take) res += "A";

        can_reach = nxt_can_reach;
    }

    reverse(res.begin(), res.end());
    cout << res << endl;
    
    return 0;
}