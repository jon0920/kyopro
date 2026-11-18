#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

struct S{
    int x, y;
};

int main(){
    
    int n, m, k;
    cin >> n >> m >> k;

    if(k == 0){
        cout << 0 << endl;
        return 0;
    }

    vector<S> pts(k + 1);
    pts[0] = {0, 0};
    for(int i = 1; i <= k; i++){
        int r, c;
        cin >> r >> c;
        r--, c--;
        pts[i] = {r, c};
    }

    auto calc = [&](S a, S b) -> ll {
        return (abs(a.x - b.x) + abs(a.y - b.y));
    };
    
    vector<vector<ll>> dp(1 << (k + 1), vector<ll>(k + 1, INF));
    dp[0][0] = 0;
    for(int i = 1; i <= k; i++){
        dp[1 << i][i] = calc(pts[0], pts[i]);
    }

    for(int s = 0; s < (1 << (k + 1)); s++){
        rep(i,k + 1){
            if(dp[s][i] == INF) continue;
            rep(j,k + 1){
                if((s >> j) & 1) continue;
                int ns = s | (1 << j);
                dp[ns][j] = min(dp[ns][j], dp[s][i] + calc(pts[i], pts[j]));
            }
        }
    }

    ll ans = INF;
    for(int i = 1; i <= k; i++){
        ans = min(ans, dp[(1 << (k + 1)) - 1][i] + calc(pts[i], pts[0]));
    }

    cout << ans << endl;
    
    return 0;
}