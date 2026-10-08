#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using mint = modint998244353;

int main(){
    
    int n;
    cin >> n;
    vector<vector<int>> G(n + 1);
    G[0].push_back(1);
    for(int i = 2; i <= n; i++){
        int p;
        cin >> p;
        G[p].push_back(i);
    }

    vector<ll> c(n + 1), d(n + 1);
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i <= n; i++) cin >> d[i];

    vector<mint> ans(n + 1, 1);
    auto dfs = [&](auto dfs, int v, int pre) -> void {
        for(int nv : G[v]){
            dfs(dfs, nv, v);
        }

        if(c[v] < d[v]){
            ans[0] = 0;
            return;
        }

        if(pre != -1){
            c[pre] += c[v] - d[v];
            ans[pre] *= ans[v];
            rep(i,d[v]){
                ans[pre] *= mint(c[v] - i);
                ans[pre] *= mint(i + 1).inv();
            }
        }
    };

    dfs(dfs, 0, -1);

    cout << ans[0].val() << endl;
    
    return 0;
}