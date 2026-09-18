#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<pair<int,ll>>> G(n);
    rep(i,m){
        int u, v;
        ll b;
        cin >> u >> v >> b;
        u--, v--;
        G[u].push_back({v,b});
        G[v].push_back({u,b});
    }

    const ll INF = 1e18;
    vector<ll> ans(n, INF);
    ans[0] = a[0];
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> que;
    que.push({a[0],0});
    while(!que.empty()){
        auto [d, v] = que.top(); que.pop();
        if(d > ans[v]) continue;

        for(auto [nv, nb] : G[v]){
            if(ans[nv] > d + nb + a[nv]){
                ans[nv] = d + nb + a[nv];
                que.push({ans[nv], nv});
            }
        }
    }

    for(int i = 1; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}