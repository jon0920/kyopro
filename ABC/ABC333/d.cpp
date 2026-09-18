#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    dsu uf(n);
    rep(i,n-1){
        int u, v;
        cin >> u >> v;
        u--, v--;
        if(u == 0 || v == 0) continue;
        uf.merge(u,v);
    }

    vector<int> sz;
    for(int i = 1; i < n; i++){
        if(uf.leader(i) == i) sz.push_back(uf.size(i));
    }

    int mx = 0;
    for(auto x : sz) mx = max(mx, x);
    
    if(sz.size() <= 1) cout << 1 << endl;
    else cout << n - mx << endl;
    
    return 0;
}