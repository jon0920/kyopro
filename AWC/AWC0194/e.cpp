#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct S{
    ll time, cost, v;
    bool operator>(const S& other) const{
        return time > other.time;
    }
};

const ll INF = 1e18;

int main(){
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<S>> G(n);
    rep(i,m){
        ll u, v, a, b, s, t;
        cin >> u >> v >> a >> b >> s >> t;
        u--, v--;
        G[u].push_back({s, a * 2, v});
        G[v].push_back({s, a * 2, u});
        G[u].push_back({t, b * 2, v});
        G[v].push_back({t, b * 2, u});
    }

    vector<vector<ll>> dp(n, vector<ll>(k + 1, INF));
    dp[0][0] = 0;

    priority_queue<S, vector<S>, greater<S>> pq;
    pq.push({0, 0, 0});

    while(!pq.empty()){
        auto [t, c, v] = pq.top(); pq.pop();
        if(dp[v][c] != t) continue;
        for(auto [nt, nc, nv] : G[v]){
            if(c + nc > k) continue;
            if(dp[nv][c + nc] <= t + nt) continue;
            dp[nv][c + nc] = t + nt;
            pq.push({dp[nv][c + nc], c + nc, nv});
        }
    }

    ll ans = INF;
    rep(i,k + 1) ans = min(ans, dp[n - 1][i]);
    cout << (ans == INF ? -1 : ans) << endl;
    
    return 0;
}