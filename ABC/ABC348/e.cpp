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
    vector<ll> c(n);
    ll tot = 0;
    rep(i,n){
        cin >> c[i];
        tot += c[i];
    }

    vector<ll> w(n);
    ll f0 = 0;
    auto dfs = [&](auto dfs, int v, int pre, ll depth) -> ll {
        f0 += c[v] * depth;
        ll sum = c[v];
        for(int nv : G[v]){
            if(nv != pre){
                sum += dfs(dfs, nv, v, depth + 1);
            }
        }
        w[v] = sum;
        return sum;
    };

    dfs(dfs, 0, -1, 0);
    
    ll ans = 4e18;
    vector<ll> f(n);
    f[0] = f0;
    auto dfs2 = [&](auto dfs2, int v, int pre) -> void {
        ans = min(ans, f[v]);
        for(int nv : G[v]){
            if(nv == pre) continue;
            f[nv] = f[v] + (tot - 2 * w[nv]);
            dfs2(dfs2, nv, v);
        }
    };

    dfs2(dfs2, 0, -1);

    cout << ans << endl;
    
    return 0;
}