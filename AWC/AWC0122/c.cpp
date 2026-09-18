#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int INF = 1e9;

int main(){
    
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> G(n);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
    }

    vector<int> step(n + 1);

    rep(i,n){
        queue<int> que;
        que.push(i);
        vector<int> dist(n, INF);
        dist[i] = 0;
        while(!que.empty()){
            int v = que.front(); que.pop();
            for(int nv : G[v]){
                if(dist[nv] != INF) continue;
                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }
        int mx = 0;
        rep(i,n) mx = max(mx, dist[i]);
        if(mx <= n) step[mx]++;
    }

    rep(i,n) step[i + 1] += step[i];

    rep(qi,q){
        int k;
        cin >> k;
        cout << step[k] << endl;
    }
    
    return 0;
}