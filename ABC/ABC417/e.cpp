#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int t;
    cin >> t;
    while(t--){
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        x--, y--;
        vector<vector<int>> G(n);
        rep(i,m){
            int u, v;
            cin >> u >> v;
            u--, v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(auto &v : G) sort(v.begin(), v.end());

        vector<bool> seen(n);
        vector<int> res;

        auto dfs = [&](auto dfs, int v) -> bool {
            res.push_back(v);
            if(v == y) return true;

            seen[v] = true;
            for(auto nv : G[v]){
                if(seen[nv]) continue;
                if(dfs(dfs, nv)) return true; 
            }
            
            res.pop_back();
            return false;
        };

        dfs(dfs, x);

        for(auto v : res) cout << v + 1 << " ";
        cout << endl;

    }

    return 0;
}