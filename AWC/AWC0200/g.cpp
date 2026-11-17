#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    dsu uf(n);
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        uf.merge(u, v);
    }

    vector<int> ans(n);
    rep(i,n){
        int r = uf.leader(i);
        ans[r] = max(ans[r], a[i]);
    }

    rep(i,n){
        cout << ans[uf.leader(i)] << endl;
    }
    
    return 0;
}