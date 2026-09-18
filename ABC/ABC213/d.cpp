#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
 
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    rep(i,n - 1){
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }    
    for(auto &v : G) sort(v.begin(), v.end());

    vector<int> ans;
    auto dfs = [&](auto dfs, int v, int pre) -> void {
        ans.push_back(v);
        for(auto nv : G[v]){
            if(nv == pre) continue;
            dfs(dfs, nv, v);
        }
        ans.push_back(pre);
    };

    dfs(dfs, 0, -1);
    ans.pop_back();
    for(auto v : ans) cout << v + 1 << " ";
    cout << endl;

    return 0;
}