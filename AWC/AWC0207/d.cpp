#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using P = pair<ll,ll>;

int main(){
    
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    vector<vector<P>> G(n);
    rep(i,n - 1){
        ll u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        G[u].push_back({v, c});
        G[v].push_back({u, c});
    }

    vector<vector<ll>> dp(n, vector<ll>(2));
    rep(i,n){
        dp[i][0] = a[i];
        dp[i][1] = b[i];
    }

    auto dfs = [&](auto dfs, int v, int p) -> void {
        for(auto [nv, c] : G[v]){
            if(nv != p){
                dfs(dfs, nv, v);
                dp[v][0] += min(dp[nv][0], dp[nv][1] + c);
                dp[v][1] += min(dp[nv][1], dp[nv][0] + c);
            }
        }
    };

    dfs(dfs, 0, -1);

    cout << min(dp[0][0], dp[0][1]) << endl;
    
    return 0;
}