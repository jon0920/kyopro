#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<vector<ll>> d(n, vector<ll>(n));
    rep(i,n){
        for(int j = i + 1; j < n; j++){
            cin >> d[i][j];
        }
    }

    vector<ll> dp(1 << n, 0);
    for(int s = 0; s < (1 << n); s++){
        rep(i,n){
            for(int j = i + 1; j < n; j++){
                if(!((s >> i) & 1) && !((s >> j) & 1)){
                    int ns = s | (1 << i) | (1 << j);
                    dp[ns] = max(dp[ns], dp[s] + d[i][j]);
                }
            }
        }
    }

    cout << dp[(1 << n) - 1] << endl;
    
    return 0;
}