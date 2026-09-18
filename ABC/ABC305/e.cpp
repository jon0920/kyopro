#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> G(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> dist(n, -1);
    priority_queue<pair<int,int>> pq;
    rep(i,k){
        int p, h;
        cin >> p >> h;
        p--;
        dist[p] = h;
        pq.push({h, p});
    }

    while(!pq.empty()){
        auto [d, v] = pq.top(); pq.pop();
        if(dist[v] != d) continue;
        for(int nv : G[v]){
            if(dist[nv] >= dist[v] - 1) continue;
            dist[nv] = dist[v] - 1;
            pq.push({dist[nv], nv});
        }
    }

    vector<int> ans;
    rep(i,n){
        if(dist[i] >= 0) ans.push_back(i + 1);
    }

    cout << ans.size() << endl;
    for(int x : ans) cout << x << " ";
    cout << endl;
    
    return 0;
}