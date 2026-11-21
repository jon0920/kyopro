#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 4e18;

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> cost(m + 1);
    ll sum = 0;
    rep(i,n){
        ll c, v;
        cin >> c >> v;
        cost[c].push_back(v);
        sum += v;
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -INF));
    fill(dp[0].begin(), dp[0].end(), 0);

    vector<ll> ans(m + 1);
    ans[m] = sum;

    int last_j = m;
    int cnt = 0;
    for(int j = m - 1; j >= 0; j--){
        if(!cost[j].empty()){
            int diff = last_j - j;
            for(int k = 1; k <= cnt; k++){
                ll shift = (ll)k * diff;
                if(shift > m){
                    fill(dp[k].begin(), dp[k].end(), -INF);
                } else {
                    for(int w = m; w >= shift; w--){
                        dp[k][w] = dp[k][w - shift];
                    }
                    for(int w = 0; w < shift; w++){
                        dp[k][w] = -INF;
                    }
                }
            }
            last_j = j;

            for(ll val : cost[j + 1]){
                sum -= val;
                for(int k = cnt; k >= 0; k--){
                    for(int w = m - 1; w >= k; w--){
                        if(dp[k][w] >= 0){
                            dp[k + 1][w + 1] = max(dp[k + 1][w + 1], dp[k][w] + val);
                        }
                    }
                }
                cnt++;
            }
        }

        int diff = last_j - j;
        ll best = 0;
        for(int k = 0; k <= cnt; k++){
            ll rem = m - (ll)k * diff;
            if(rem < 0) break;
            if(dp[k][rem] >= 0) best = max(best, dp[k][rem]);
        }
        ans[j] = sum + best;
    }

    for(auto x : ans) cout << x << endl;
    
    return 0;
}