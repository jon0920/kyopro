#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

const pair<ll,ll> UNVISITED = {-1, -1};

struct S{
    int id; ll x; ll y;
};

int main() {
    
    int n, m;
    cin >> n >> m;
    vector<vector<S>> G(n);
    rep(i,m){
        int a, b;
        ll x, y;
        cin >> a >> b >> x >> y;
        a--, b--;
        G[a].push_back({b, x, y});
        G[b].push_back({a, -x, -y});
    }

    vector<pair<ll,ll>> pos(n, {-1, -1});
    pos[0] = {0, 0};
    queue<S> que;
    que.push({0, 0, 0});
    
    while(!que.empty()){
        auto [id, x, y] = que.front(); que.pop();
        for(auto [nid, nx, ny] : G[id]){
            if(pos[nid] != UNVISITED) continue;

            pos[nid] = {x + nx, y + ny};
            que.push({nid, x + nx, y + ny});
        }
    }

    for(auto p : pos){
        if(p == UNVISITED) cout << "undecidable" << endl;
        else cout << p.first << " " << p.second << endl;
    }
    
    return 0;
}