#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m);
    vector<pair<int,int>> c(m);
    rep(i,m){
        int K, C;
        cin >> K >> C;
        c[i] = {C, i};
        a[i].resize(K);
        rep(j,K){
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    sort(c.begin(), c.end());

    dsu uf(n);
    ll ans = 0;
    rep(i,m){
        auto [cost, id] = c[i];
        int sz = a[id].size();
        for(int j = 1; j < sz; j++){
            if(!uf.same(a[id][0], a[id][j])){
                ans += cost;
                uf.merge(a[id][0], a[id][j]);
            }
        }
    }

    int l = uf.leader(0);
    rep(i,n){
        if(l != uf.leader(i)){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    
    return 0;
}