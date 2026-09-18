#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m;
    cin >> n >> m;
    dsu uf(n);
    //cnt := 残したい辺
    int cnt = 0;
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        if(!uf.same(u,v)) uf.merge(u,v), cnt++;
    }
    cout << m - cnt << endl;
    
    return 0;
}