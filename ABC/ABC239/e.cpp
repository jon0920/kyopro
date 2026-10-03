#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<int> x(n);
    rep(i,n) cin >> x[i];
    vector<vector<int>> G(n);
    rep(i,n - 1){
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<vector<int>> subtree(n);
    rep(i,n) subtree[i].push_back(x[i]);

    auto dfs = [&](auto dfs, int now, int pre) -> void {
        for(int nxt : G[now]){
            if(nxt != pre){
                dfs(dfs, nxt, now);
            }
        }
        if(pre != -1){
            for(int val : subtree[now]){
                subtree[pre].push_back(val);
            }
            sort(subtree[pre].rbegin(), subtree[pre].rend());
            if(subtree[pre].size() > 20) subtree[pre].resize(20);
        }
    };

    dfs(dfs, 0, -1);

    while(q--){
        int v, k;
        cin >> v >> k;
        v--, k--;
        cout << subtree[v][k] << endl;
    }
    
    return 0;
}