#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    vector<int> ac;
    vector<bool> ok(n);
    rep(i,n){
        int a, b;
        cin >> a >> b;
        if(a == 0 && b == 0){
            ac.push_back(i);
        } else {
            a--, b--;
            G[a].push_back(i);
            G[b].push_back(i);
        }
    }

    auto dfs = [&](auto dfs, int v) -> void {
        ok[v] = true;
        for(auto nv : G[v]){
            if(!ok[nv]) dfs(dfs, nv);
        }
    };

    for(auto v : ac){
        if(!ok[v]) dfs(dfs, v);
    }

    int ans = 0;
    for(auto i : ok) if(i) ans++;
    cout << ans << endl;
    
    return 0;
}