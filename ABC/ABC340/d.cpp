#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

const ll INF = 1e18;

int main() {
    
    int n;
    cin >> n;
    vector<vector<pair<ll,ll>>> G(n);
    rep(i,n-1){
        ll a, b, x;
        cin >> a >> b >> x;
        x--;
        G[i].push_back({i + 1, a});
        G[i].push_back({x, b});
    }

    vector<ll> dist(n,INF);
    dist[0] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> que;
    que.push({0,0});
    while(!que.empty()){
        auto [d, idx] = que.top(); que.pop();
        if(d > dist[idx]) continue;

        for(auto v : G[idx]){
            int to = v.first;
            ll cost = v.second;
            if(d + cost < dist[to]){
                dist[to] = d + cost;
                que.push({dist[to], to});
            }
        }
    }
    cout << dist[n - 1] << endl;
    
    return 0;
}