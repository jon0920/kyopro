#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    dsu uf(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
        uf.merge(a,b);
    }

    bool ans = true;
    for(auto v : G) if(v.size() != 2) ans = false;
    if(uf.size(0) != n) ans = false;
    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}