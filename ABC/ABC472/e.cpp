#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> G(n);
        rep(i,m){
            int a, b;
            cin >> a >> b;
            a--, b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        vector<int> color(n, -1);
        vector<int> parent(n, -1);
        int ini = -1, fin = -1;

        auto dfs = [&](auto dfs, int v, int pre, int c) -> bool {
            color[v] = c;
            parent[v] = pre;

            for(int nv : G[v]){
                if(nv != pre){
                    if(color[nv] == -1){
                        if(dfs(dfs, nv, v, c ^ 1)) return true;
                    } else if(color[v] == color[nv]){
                        ini = v;
                        fin = nv;
                        return true;
                    }
                }
            }
            return false;
        };

        if(!dfs(dfs, 0, -1, 0)) cout << -1 << endl;
        else{
            vector<int> res;
            int cur = ini;
            while(cur != fin){
                res.push_back(cur);
                cur = parent[cur];
            }
            res.push_back(fin);
            cout << res.size() << endl;
            for(int x : res) cout << x + 1 << " ";
            cout << endl;
        }
    }

    
    return 0;
}