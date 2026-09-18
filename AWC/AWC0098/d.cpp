#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); i++)

int main(){
    
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<ll> p(n);
    rep(i,n) cin >> p[i];
    vector<pair<int,int>> edges(m);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[i] = {u, v};
    }

    vector<vector<ll>> dp(k, vector<ll>(n, -1));
    rep(i,n) dp[0][i] = p[i] % q;
    
    rep(i,k - 1){
        rep(j,m){
            auto [u, v] = edges[j];
            if(dp[i][u] == -1) continue;
            dp[i + 1][v] = max(dp[i + 1][v], (dp[i][u] + (p[v] * (i + 2)) % q));
        }
    }

    cout << *max_element(dp[k - 1].begin(), dp[k - 1].end()) << endl;
    
    return 0;
}