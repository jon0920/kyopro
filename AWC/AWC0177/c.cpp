#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<ll> c(n);
    rep(i,n) cin >> c[i];
    vector<vector<int>> G(n);
    for(int i = 1; i < n; i++){
        int p;
        cin >> p;
        p--;
        G[p].push_back(i);
    }

    vector<bool> use(n);
    rep(i,k){
        int a;
        cin >> a;
        a--;
        use[a] = true;
    }

    auto dfs = [&](auto dfs, int v, int pre) -> void {
        for(int nv : G[v]){
            if(nv != pre) dfs(dfs, nv, v);
        }
        if(pre != -1){
            if(use[v]) use[pre] = true;
        }
    };

    dfs(dfs, 0, -1);

    ll ans = 0;
    rep(i,n) if(use[i]) ans += c[i];
    cout << ans << endl;
    
    return 0;
}