#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> G(n);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<bool> seen(n);
    rep(i,k){
        int b;
        cin >> b;
        b--;
        seen[b] = true;
    }
    vector<int> dist(n, -1);
    dist[n - 1] = 0;
    seen[n - 1] = true;
    queue<int> que;
    que.push(n - 1);

    while(!que.empty()){
        int v = que.front(); que.pop();
        for(int nv : G[v]){
            if(seen[nv]) continue;
            seen[nv] = true;
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

    cout << dist[0] << endl;
    
    return 0;
}