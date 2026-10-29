#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct P{
    ll x, y, z;
};

const ll INF = 1e18;

int main(){
    
    int n;
    cin >> n;
    vector<P> pts(n);
    rep(i,n) cin >> pts[i].x >> pts[i].y >> pts[i].z;

    auto calc = [&](P a, P b){
        return (abs(a.x - b.x) + abs(a.y - b.y) + max(0LL, b.z - a.z));
    };

    vector<vector<ll>> dp(1<<n, vector<ll>(n, INF));
    dp[0][0] = 0;
    
    for(int i = 1; i < n; i++){
        dp[1<<i][i] = calc(pts[0], pts[i]);
    }

    for(int s = 0; s < (1 << n); s++){
        rep(i,n){
            if(dp[s][i] == INF) continue;
            rep(j,n){
                if((s >> j) & 1) continue;
                int ns = s | (1 << j);
                dp[ns][j] = min(dp[ns][j], dp[s][i] + calc(pts[i], pts[j]));
            }
        }
    }

    ll ans = INF;
    for(int i = 1; i < n; i++){
        ans = min(ans, dp[(1 << n) - 1][i] + calc(pts[i], pts[0]));
    }

    cout << ans << endl;
    
    return 0;
}