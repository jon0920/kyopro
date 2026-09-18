#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;

void chmax(ll& a, ll b) {a = max(a,b);}

int main() {

    int n; 
    cin >> n;
    int W = 0; ll sumb = 0;
    vector<pair<int,int>> ps;
    rep(i,n){
        int w, h, b;
        cin >> w >> h >> b;
        W += w;
        sumb += b;
        if(h > b) ps.emplace_back(w, h-b);
    }

    n = ps.size();
    const ll INF = 1e18;
    W /= 2;
    vector dp(n+1, vector<ll>(W+1, -INF));
    dp[0][0] = 0;

    rep(i,n){
        auto [w,v] = ps[i];
        rep(j,W+1){
            chmax(dp[i+1][j], dp[i][j]);
            if (j+w <= W) chmax(dp[i+1][j+w], dp[i][j]+v);
        }
    }

    ll ans = -INF;
    rep(j,W+1) chmax(ans, dp[n][j]);
    cout << ans + sumb << endl;
    return 0;
}
