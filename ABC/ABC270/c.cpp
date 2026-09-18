#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int n, x, y;
vector<vector<int>> G;
vector<int> ans, path;
vector<bool> seen;

void dfs(int v){
    if(v == y){
        ans = path;
        return;
    }

    seen[v] = true;
    for(auto nv : G[v]){
        if(!seen[nv]){
            path.push_back(nv);
            dfs(nv);
            path.pop_back();
        }
    }
    return;
}

int main(){

    cin >> n >> x >> y;
    x--, y--;
    G.resize(n);
    seen.resize(n);
    rep(i,n-1){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    path.push_back(x);
    dfs(x);

    for(auto v : ans) cout << v + 1 << " ";
    cout << endl;

    return 0;
}