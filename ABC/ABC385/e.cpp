#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    vector<int> deg(n);
    rep(i,n - 1){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
        deg[u]++; deg[v]++;
    }

    ll ans = n;
    rep(i,n){
        vector<ll> cnt;
        for(int v : G[i]){
            cnt.push_back(deg[v] - 1);
        }
        sort(cnt.rbegin(), cnt.rend());
        int sz = cnt.size();
        rep(x,sz){
            ans = min(ans, n - (1 + (x + 1) * (cnt[x] + 1)));
        }
    }
    cout << ans << endl;
    
    return 0;
}