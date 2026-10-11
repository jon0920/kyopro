#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n;
    cin >> n;
    vector<vector<pair<ll,ll>>> G(n);
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back({b, i});
        G[b].push_back({a, i});
    }

    vector<int> sz(n, 1);
    vector<ll> add(n), ans(n);
    ll base = 0;

    auto dfs1 = [&](auto dfs1, int v, int p) -> void {
        for(auto [nv, id] : G[v]){
            if(nv == p) continue;
            dfs1(dfs1, nv, v);

            sz[v] += sz[nv];
            if(sz[nv] > n - sz[nv]){
                add[nv] += id;
            } else {
                base += id;
                add[nv] -= id;
            }
        }
    };

    auto dfs2 = [&](auto dfs2, int v, int p, ll sum) -> void {
        sum += add[v];
        ans[v] += base + sum;
        for(auto [nv, id] : G[v]){
            if(nv == p) continue;
            dfs2(dfs2, nv, v, sum);
        }
    };

    dfs1(dfs1, 0, -1);
    dfs2(dfs2, 0, -1, 0);

    for(ll x : ans) cout << x << " ";
    cout << endl;
    
    return 0;
}