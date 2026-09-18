#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    rep(i,m){
        int u, v, s;
        cin >> u >> v >> s;
        u--, v--;
        if(s == 1){
            G[u].push_back(v);
            G[v].push_back(u);
        }
    }

    vector<int> dist(n, -1);
    dist[0] = 0;
    queue<int> que;
    que.push(0);

    while(!que.empty()){
        int v = que.front(); que.pop();
        for(int nv : G[v]){
            if(dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

    cout << dist[n - 1] << endl;
    
    return 0;
}