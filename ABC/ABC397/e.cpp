#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<vector<int>> G(n * k);
    rep(i,n * k - 1){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    bool ok = true;
    auto dfs = [&](auto dfs, int v, int pre) -> int {
        vector<int> open;
        for(int nv : G[v]){
            if(nv != pre){
                int a = dfs(dfs, nv, v);
                if(a > 0) open.push_back(a);
            }
        }
        int sz = open.size();
        if(sz == 0){
            if(k == 1) return 0;
            else return 1;
        } else if(sz == 1){
            if(open[0] + 1 == k) return 0;
            else return open[0] + 1;
        } else if(sz == 2){
            if(open[0] + open[1] + 1 == k) return 0;
            else{
                ok = false;
                return 0;
            }
        } else {
            ok = false;
            return 0;
        }
    };

    int root = dfs(dfs, 0, -1);
    if(root != 0) ok = false;
    
    cout << (ok ? "Yes" : "No") << endl;
    
    return 0;
}