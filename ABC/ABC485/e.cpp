#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> G(n);
    rep(i,m){
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        G[u].push_back({v, c});
    }

    const int INF = 1e9;
    vector<pair<int,int>> first_dist(n, {INF, -1});
    vector<int> second_dist(n, INF);
    first_dist[0] = {0, -1};

    queue<tuple<int,int,int>> que;
    que.push({0, -1, 0});

    while(!que.empty()){
        auto [v, pc, d] = que.front(); que.pop();
        for(auto [nv, nc] : G[v]){
            if(nc == pc) continue;

            if(first_dist[nv].first == INF){
                first_dist[nv] = {d + 1, nc};
                que.push({nv, nc, d + 1});
            } else if(second_dist[nv] == INF && first_dist[nv].second != nc){
                second_dist[nv] = d + 1;
                que.push({nv, nc, d + 1});
            }
        }
    }

    if(first_dist[n - 1].first == INF) cout << -1 << endl;
    else cout << first_dist[n - 1].first << endl;
    
    return 0;
}