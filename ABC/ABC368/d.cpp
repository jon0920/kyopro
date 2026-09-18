#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, k;
    cin >> n >> k;
    vector<vector<int>> G(n);
    rep(i,n - 1){
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    vector<bool> V(n);
    int s;
    rep(i,k){
        int v;
        cin >> v;
        v--;
        V[v] = true;
        s = v;
    }
    
    int ans = 0;
    auto dfs = [&](auto dfs, int v, int p) -> bool {
        bool is_need = false;

        if(V[v]) is_need = true;

        for(auto nv : G[v]){
            if(nv == p) continue;
            if(dfs(dfs, nv, v)) is_need = true;
        }

        if(is_need) ans++;

        return is_need;
    };

    dfs(dfs, s, -1);

    cout << ans << endl;

    return 0;
}