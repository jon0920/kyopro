#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<ll,ll>;
const ll INF = 1e18;

int main(){

    int n, m;
    cin >> n >> m;
    vector<int> s(n);
    rep(i,n) cin >> s[i];
    vector<vector<P>> G(n);
    rep(i,m){
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    vector<int> c(n);
    vector<vector<bool>> fr(n, vector<bool>(n));

    rep(i,n){
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, i});
        vector<ll> dist(n, INF);
        dist[i] = 0;
        while(!pq.empty()){
            auto [c, v] = pq.top(); pq.pop();
            if(dist[v] != c) continue;
            for(auto [nv, nc] : G[v]){
                if(dist[nv] <= dist[v] + nc) continue;
                dist[nv] = dist[v] + nc;
                pq.push({dist[nv], nv});
            }
        }
        int cnt = 0;
        rep(j,n){
            if(i != j && dist[j] <= s[i]){
                cnt++;
                fr[i][j] = true;
            }
        }
        c[i] = cnt;
    }

    int ans = 0;
    rep(i,n){
        for(int j = i + 1; j < n; j++){
            if(fr[i][j] && fr[j][i] && c[i] == c[j]) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}