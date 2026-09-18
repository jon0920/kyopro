#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--, t--;
    vector<vector<pair<int,int>>> G(n + m);
    rep(i,m){
        int k;
        cin >> k;
        rep(j,k){
            int a;
            cin >> a;
            a--;
            G[a].push_back({n + i, 0});
            G[n + i].push_back({a, 1});
        }
    }

    vector<ll> dist(n + m, INF);
    dist[s] = 0;
    deque<int> dq;
    dq.push_back(s);

    while(!dq.empty()){
        int v = dq.front(); dq.pop_front();
        for(auto [nv, c] : G[v]){
            if(dist[nv] > dist[v] + c){
                dist[nv] = dist[v] + c;
                if(c == 0) dq.push_front(nv);
                else dq.push_back(nv);
            }
        }
    }

    if(dist[t] == INF) cout << -1 << endl;
    else cout << dist[t] << endl;

    return 0;
}