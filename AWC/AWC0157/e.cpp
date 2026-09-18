#include <bits/stdc++.h>
#include <atcoder/scc>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int INF = 1e9;

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n);
    rep(i,n){
        int w;
        cin >> w;
        cnt[i] -= w;
    }
    rep(i,n){
        int t;
        cin >> t;
        cnt[i] += t;
    }

    scc_graph G(n);
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        G.add_edge(u, v);
    }

    auto scc = G.scc();

    ll ans = 0;
    for(auto v : scc){
        int mx = -INF;
        for(int x : v) mx = max(mx, cnt[x]);
        
        if(v.size() == 1 && mx > 0){
            cout << -1 << endl;
            return 0;
        }

        ans += max(0, mx);
    }
    cout << ans << endl;
    
    return 0;
}