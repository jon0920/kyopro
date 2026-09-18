#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> dist(m, vector<ll>(m, 1e9));
    rep(i,k){
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        dist[u][v] = w;
        dist[v][u] = w;
    }

    rep(l,m){
        rep(i,m){
            rep(j,m) dist[i][j] = min(dist[i][j], dist[i][l] + dist[l][j]);
        }
    }

    ll ans = 0;
    while(n--){
        int s, t;
        cin >> s >> t;
        s--, t--;
        ans += dist[s][t];
    }

    cout << ans << endl;
    
    return 0;
}