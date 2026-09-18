#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){
    
    int n, W;
    cin >> n >> W;

    vector<ll> dp(W + 1, -INF);
    dp[0] = 0;

    rep(i,n){
        int w; ll v;
        cin >> w >> v;
        vector<ll> ndp = dp;
        rep(j,W + 1){
            if(dp[j] == -INF) continue;
            ndp[j] = max(ndp[j], dp[j]);
            if(j + w <= W) ndp[j + w] = max(ndp[j + w], dp[j] + v); 
        }
        dp = ndp;
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
    
    return 0;
}