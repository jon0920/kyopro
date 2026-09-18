#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

ll n, m, l, s, t;
vector<vector<pair<ll,ll>>> G;
set<int> ans;

void dfs(int lv, int v, ll cost){
    if(lv == l){
        if(cost >= s && cost <= t) ans.insert(v);
        return;
    }

    for(auto p : G[v]){
        auto [nv, c] = p;
        dfs(lv + 1, nv, cost + c);
    }
    return;
}

int main(){

    cin >> n >> m >> l >> s >> t;
    G.resize(n);
    rep(i,m){
        ll u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        G[u].push_back({v, c});
    }

    dfs(0,0,0);
    for(auto v : ans) cout << v + 1 << " ";
    cout << endl;
        
    return 0;
}