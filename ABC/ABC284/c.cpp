#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> dist(n, -1);
    int ans = 0;
    rep(i,n){
        if(dist[i] == -1){
            ans++;
            queue<int> que;
            que.push(i);
            dist[i] = 0;
            while(!que.empty()){
                int v = que.front(); que.pop();
                for(auto nv : G[v]){
                    if(dist[nv] == -1){
                        que.push(nv);
                        dist[nv] = 0;
                    }
                }
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}