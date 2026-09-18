#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<vector<int>> G(n);
    rep(i,n){
        int c;
        cin >> c;
        rep(j,c){
            int p;
            cin >> p;
            p--;
            G[i].push_back(p);
        }
    }

    vector<int> res;
    vector<bool> seen(n);
    auto dfs = [&](auto dfs, int v) -> void {
        seen[v] = true;
        for(auto nv : G[v]){
            if(!seen[nv]) dfs(dfs, nv);
        }
        if(v != 0) res.push_back(v);
    };

    dfs(dfs, 0);

    for(auto x : res) cout << x + 1 << " ";
    cout << endl;

    return 0;
}