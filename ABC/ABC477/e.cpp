#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using P = pair<ll,ll>;
const ll INF = 1e18;

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<vector<P>> G(n + 1);
    vector<ll> a(n);
    ll tot = 0;
    rep(i,n){
        cin >> a[i];
        tot += a[i];
        G[i].push_back({(i + 1) % n, a[i]});
        G[(i + 1) % n].push_back({i, a[i]});
    }
    rep(i,n){
        ll b;
        cin >> b;
        G[i].push_back({n, b});
        G[n].push_back({i, b});
    }

    vector<ll> sum(n + 1);
    rep(i,n) sum[i + 1] = sum[i] + a[i];

    vector<ll> dist(n + 1, INF);
    dist[n] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, n});
    while(!pq.empty()){
        auto [c, v] = pq.top(); pq.pop();
        if(c != dist[v]) continue;
        for(auto [nv, nc] : G[v]){
            if(dist[nv] <= dist[v] + nc) continue;
            dist[nv] = dist[v] + nc;
            pq.push({dist[nv], nv});
        }
    }

    while(q--){
        int s, t;
        cin >> s >> t;
        s--, t--;
        if(t == n){
            cout << dist[s] << endl;
        } else {
            ll d1 = dist[s] + dist[t];
            ll d2 = sum[t] - sum[s];
            ll d3 = tot - d2;
            cout << min({d1, d2, d3}) << endl;
        }
    }

    return 0;
}