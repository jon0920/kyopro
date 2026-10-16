#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); i++)

int main(){
    
    ll n;
    cin >> n;
    vector<vector<pair<ll,ll>>> G(n * 2);
    rep(i,n - 1){
        ll a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back({b, n * 2 + 1});
        G[b].push_back({a, n * 2 + 1});
    }

    rep(i,n){
        G[i].push_back({i + n, i + 1});
        G[i + n].push_back({i, i + 1});
    }

    auto BFS = [&](ll init) {
        vector<ll> dist(n * 2, -1);
        queue<ll> que;
        que.push(init);
        dist[init] = 0;
        while(!que.empty()){
            ll v = que.front(); que.pop();
            for(auto [nv, w] : G[v]){
                if(dist[nv] == -1){
                    dist[nv] = dist[v] + w;
                    que.push(nv);
                }
            }
        }
        return dist;
    };

    vector<ll> dist = BFS(0);
    int s = 0;
    rep(i,n * 2){
        if(dist[i] > dist[s]) s = i;
    }

    vector<ll> dist_s = BFS(s);
    int t = 0;
    rep(i,n * 2){
        if(dist_s[i] > dist_s[t]) t = i;
    }

    vector<ll> dist_t = BFS(t);

    rep(i,n){
        int res = (dist_s[i] > dist_t[i] ? s : t);
        cout << res - n + 1 << endl;
    }
    
    return 0;
}