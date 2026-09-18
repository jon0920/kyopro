#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m, s;
    cin >> n >> m >> s;
    s--;
    vector<vector<int>> G(n);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
    }

    vector<int> dist(n, -1);
    dist[s] = 0;
    queue<int> que;
    que.push(s);
    
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(auto nv : G[v]){
            if(dist[nv] == -1){
                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }
    }

    int ans = 0;
    rep(i,n){
        if(dist[i] == -1){
            ans = -1;
            break;
        }
        ans = max(ans, dist[i]);
    }
    cout << ans << endl;
    
    return 0;
}