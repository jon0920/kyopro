#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){

    ll n, d, s, t;
    cin >> n >> d >> s >> t;
    s--, t--;
    vector<pair<ll,ll>> xy(n);
    rep(i,n){
        ll x, y;
        cin >> x >> y;
        xy[i] = {x, y};
    }

    vector<vector<int>> G(n);
    rep(i,n){
        for(int j = i + 1; j < n; j++){
            auto [xi, yi] = xy[i];
            auto [xj, yj] = xy[j];
            if((xi - xj) * (xi - xj) + (yi - yj) * (yi - yj) <= d * d){
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }

    queue<int> que;
    que.push(s);
    vector<ll> dist(n, INF);
    dist[s] = 0;

    while(!que.empty()){
        int v = que.front(); que.pop();
        for(auto nv : G[v]){
            if(dist[nv] != INF) continue;

            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

    if(dist[t] != INF) cout << dist[t] << endl;
    else cout << -1 << endl;

    return 0;
}