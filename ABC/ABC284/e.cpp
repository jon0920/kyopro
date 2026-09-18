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

    vector<bool> seen(n);
    int ans = 0;
    auto dfs = [&](auto dfs, int v) -> void {
        seen[v] = true;
        ans++;
        if(ans >= 1e6){
            ans = 1e6;
            return;
        }
        for(auto nv : G[v]){
            if(!seen[nv]){
                dfs(dfs, nv);
            }
        }
        seen[v] = false;
    };

    dfs(dfs, 0);
    cout << ans << endl;
    
    return 0;
}