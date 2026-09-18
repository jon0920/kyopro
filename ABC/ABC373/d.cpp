#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,ll>>> G(n);
    rep(i,m){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--, v--;
        G[u].push_back({v, w});
        G[v].push_back({u, -w});
    }

    vector<ll> ans(n, 0);
    vector<bool> visited(n, false);
    queue<int> que;
    rep(i,n){
        if(visited[i]) continue;
        
        visited[i] = true;
        que.push(i);
        while(!que.empty()){
            int x = que.front(); que.pop();
            for(auto nx : G[x]){
                auto [nv, nw] = nx;
                if(visited[nv]) continue;
                
                visited[nv] = true;
                ans[nv] = ans[x] + nw;
                que.push(nv);
            }
        }
    }
    for(auto x : ans) cout << x << " ";
    cout << endl;
    
    return 0;
}