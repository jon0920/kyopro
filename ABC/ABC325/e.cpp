#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

struct S{
    ll cost;
    int u;
    int mode;
    bool operator>(const S &o) const {
        return cost > o.cost;
    }
};

int main(){
    
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<vector<ll>> d(n, vector<ll>(n));
    rep(i,n) rep(j,n) cin >> d[i][j];

    vector<vector<ll>> dist(n, vector<ll>(2, INF));
    dist[0][0] = 0;
    priority_queue<S, vector<S>, greater<S>> pq;
    pq.push({0, 0, 0});

    while(!pq.empty()){
        auto [cost, u, mode] = pq.top(); pq.pop();
        if(dist[u][mode] != cost) continue;

        if(mode == 0){
            if(dist[u][1] > dist[u][0]){
                dist[u][1] = dist[u][0];
                pq.push({dist[u][1], u, 1});
            }
        }

        rep(v,n){
            if(u != v){
                if(mode == 0){
                    if(dist[v][0] > dist[u][0] + d[u][v] * a){
                        dist[v][0] = dist[u][0] + d[u][v] * a;
                        pq.push({dist[v][0], v, 0});
                    }
                    if(dist[v][1] > dist[u][0] + d[u][v] * b + c){
                        dist[v][1] = dist[u][0] + d[u][v] * b + c;
                        pq.push({dist[v][1], v, 1});
                    }
                } else {
                    if(dist[v][1] > dist[u][1] + d[u][v] * b + c){
                        dist[v][1] = dist[u][1] + d[u][v] * b + c;
                        pq.push({dist[v][1], v, 1});
                    }
                }
            }
        }
    }

    cout << min(dist[n - 1][0], dist[n - 1][1]) << endl;
    
    return 0;
}