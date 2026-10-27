#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<int>> G(n);
    vector<int> deg(n);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        deg[v]++;
    }

    vector<ll> dist(n);
    queue<int> que;
    rep(i,n){
        if(deg[i] == 0) que.push(i);
    }

    while(!que.empty()){
        int v = que.front(); que.pop();
        for(int nv : G[v]){
            dist[nv] = max(dist[nv], dist[v] + a[v]);
            deg[nv]--;
            if(deg[nv] == 0) que.push(nv);
        }
    }

    bool ok = true;
    rep(i,n) if(deg[i] >= 1) ok = false;
    if(!ok) cout << -1 << endl;
    else {
        ll ans = 0;
        rep(i,n) ans = max(ans, dist[i] + a[i]);
        cout << ans << endl;
    }
    
    return 0;
}